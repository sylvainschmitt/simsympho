plot.nichehiking <- function(nichehiking){
  require(tidyverse)
  theme_set(bayesplot::theme_default())
  nichehiking %>% 
    reshape2::melt("age") %>% 
    mutate(variable = recode(variable, 
                             "tprop" = "Torch proportion", 
                             "fit" = "Mean fitness",
                             "tfit" = "Torch mean fitness",
                             "dfit" = "Damp mean fitness")) %>% 
    ggplot(aes(age, value)) +
    geom_point(alpha = 0.1) +
    geom_line() +
    xlab("Time (fire events)") +
    facet_wrap(~ variable, ncol = 1, scales = "free")
}
