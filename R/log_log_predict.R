
log_log_predict = function(x, y, x_predict){

    # take logs
    x = log(x)
    y = log(y)

    # linear regression
    r = lm( y ~ x)
    
    # get r squared
    r2 = summary(r)$r.squared 

    x = data.frame(x = log(x_predict))

    p = predict(r, x, interval = "conf")
    p = exp( data.frame(x, p) )

    names(p) = c(
		 "x",
		 "fit",
		 "lwr",
		 "upr"
		 )


    output = list(
		  r_square = r2, 
		  prediction = p
		  )

    return(output)

}
