# simsympho

*I should probably change the name later.*

This is a quick exploration of reusing the model from [Schwilt and Kerr (2002)](https://github.com/dschwilk/ms-data-Oikos-2002) to model the eco-evolutionnary dynamics of *Symphonia globulifera* with topography and forest gaps dynamics based on PhD results.

## Installation

```
devtools::install_github("sylvainschmitt/simsympho")
```

## Test

```
nichehiking(grid = 100, torch_init = 0.5, cycles = 1, agemax = 100) %>% 
  plot.nichehiking()
```

## News

* started integration as `Rcpp` package
* fixed Rcpp
* `pkgdown`

## ToDo

* start versionning and all packageing stuff
