
growth_rate = function(x, t){

    n = length(x)

    gr = ( x[-1] / x[-n] - 1 ) * 100
    year = t[-n]

    output = data.table( year = year, gr = gr)

    return(output)

}
