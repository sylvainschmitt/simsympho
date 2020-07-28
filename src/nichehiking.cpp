// Without stability criterion
#include "TPlant.h"
#include "dws_random.h"
#include "TLandscape.h"
#include <fstream>
#include <ctime>
#include <valarray>
#include <Rcpp.h>
using namespace Rcpp;

double average(double *a , int n);
void WriteSample(const DWS::TBivSample& Sam);

// [[Rcpp::export]]
List nichehiking_cpp(
    int grid = 100,
    double torch_init = 0.005,
    int cycles = 1,
    int agemax = 1000,
    int changePeriod = 8,
    double mortRate = 0.1,
    int pneigh = 3,
    int sneigh = 3,
    int bneigh = 3,
    double mu = 0.00001,
    double r = 0.08,
    bool verbose = TRUE
) {
  
  DWS::set_randomizer_seed(-100);
  time_t   start;
  time( &start );

	DWS::TSample TFitS;
	DWS::TSample DFitS;

	NumericVector age_vec(agemax);
	NumericVector tprop_vec(agemax);
	NumericVector fit_vec(agemax);
	NumericVector tfit_vec(agemax);
	NumericVector dfit_vec(agemax);

	double fit, tprop=0;
	DWS::TSample AgeSample;
	TLandscape LS(grid);
	LS.SetChangePeriod(changePeriod);
	LS.SetMortalityRate(mortRate);
	LS.SetSeedNeighborhood(sneigh);
	LS.SetPollenNeighborhood(pneigh);
	LS.SetBurnNeighborhood(bneigh);
	LS.Setr(r);
	LS.SetMutationRate(mu);
	if(verbose) std::cout << "new landscape" << std::endl;	
	for(int i = 0; i < agemax; ++i) {
	  LS.RunForCycles(cycles);
	  LS.TorchDampFitness(TFitS, DFitS);
	  if(verbose) std::cout << LS.Age() << '\t' << pneigh << '\t' << changePeriod << '\t' << mortRate << '\t' << LS.MeanFitness() << '\t' << fit << '\t' << LS.TorchProp() << std::endl;
	  age_vec[i] = LS.Age();
	  tprop_vec[i] = LS.TorchProp();
	  fit_vec[i] = LS.MeanFitness();
	  tfit_vec[i] = TFitS.Mean();
	  dfit_vec[i] = DFitS.Mean();
	  if (LS.Age() == 100) { // 100
	    if(verbose) std::cout << "Adding torches" << std::endl;
	    LS.AddTorches(torch_init);
	  }
	  // if(LS.Age()==10007) {
	  // LS.WriteFitnessGrid(fitgrids);
	  // LS.WriteFlamGrid(flamgrids);
	  // }
	  if(tprop > 0.80) break; // 1
	}
	List z = List::create( age_vec, tprop_vec, fit_vec, tfit_vec, dfit_vec ) ;
	return z ;
}


double average(double *a , int n){
	double r=0;
	for(int i=0;i<n;i++) r+=a[i];
	return(r/double(n));
}


