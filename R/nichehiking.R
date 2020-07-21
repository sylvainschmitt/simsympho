#' Title
#'
#' @param grid 
#' @param torch_init 
#' @param cycles 
#' @param agemax 
#' @param changePeriod 
#' @param mortRate 
#' @param pneigh 
#' @param sneigh 
#' @param bneigh 
#' @param mu 
#' @param r 
#'
#' @return
#' @export
#'
#' @examples
nichehiking <- function(
  grid = 100,
  torch_init = 0.005,
  cycles = 1,
  agemax = 1000,
  changePeriod = 8,
  mortRate = 0.1,
  pneigh = 3,
  sneigh = 3,
  bneigh = 3,
  mu = 0.00001,
  r = 0.08
){
  res.l <- nichehiking_cpp(
    grid = grid, 
    torch_init = torch_init, 
    cycles = cycles, 
    agemax = agemax,
    changePeriod = changePeriod,
    mortRate = mortRate,
    pneigh = pneigh,
    sneigh = sneigh,
    bneigh = bneigh,
    mu = mu,
    r = r
    )
  res.df <- data.frame(
    age = res.l[[1]],
    tprop = res.l[[2]],
    fit = res.l[[3]], 
    tfit = res.l[[4]], 
    dfit = res.l[[5]]
  )
  return(res.df)
}
