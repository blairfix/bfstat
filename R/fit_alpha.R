fit_alpha = function(x){

    xmin = min(x) 
    sum_log = sum( log( x / xmin ) )

    alpha = 1 + length(x) / sum_log;

    return(alpha)

}
