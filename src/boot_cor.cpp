#include <RcppArmadillo.h>

// [[Rcpp::depends(RcppArmadillo)]]
// [[Rcpp::plugins(cpp11)]]
// [[Rcpp::export]]


arma::rowvec boot_cor (
		    arma::vec & x,
		    arma::vec & y,
		    double n_boot,
		    double conf
		    )
{
    // container for boostrap correlations
    arma::vec bootstraps(n_boot);

    // do bootstrap correlation n_boot times
    for( int i = 0; i < n_boot; i++) {


	// size of sample
	int n = x.size();

	// make indexs of random sample
	// sample has n elements composed of integers 
	// that range from 0 to n - 1
	arma::vec ru = arma::randu( n );
	arma::vec id_tmp = arma::floor( n * ru );
	arma::uvec id = arma::conv_to<arma::uvec>::from(id_tmp);

	// get sample of x and y
	arma::vec x_samp = x(id);
	arma::vec y_samp = y(id);

	// get correlation
	arma::mat samp_cor = arma::cor( x_samp, y_samp );

	// put it in the bootstrap vector
	bootstraps[i] = samp_cor(0, 0);

    }

    // get average value of bootstrap
    double boot_mean = arma::mean(bootstraps);

    // sort the bootstrap values
    arma::vec boot_sorted = arma::sort(bootstraps);
    
    // get lower confidence interval
    double alpha = (1 - conf) / 2;
    int id_lwr = n_boot * alpha;
    double boot_lwr = boot_sorted[id_lwr];

    // get upper confidence interval
    int id_upr = n_boot * (1 - alpha);
    double boot_upr = boot_sorted[id_upr];
    
    // bind the results
    arma::rowvec output = {
			   boot_lwr,
			   boot_mean,
			   boot_upr
			  };


    return output;
}
