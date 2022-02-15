#include <RcppArmadillo.h>

// [[Rcpp::depends(RcppArmadillo)]]
// [[Rcpp::export]]


arma::rowvec boot_cor_null (
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

	// first random sample of indexes
	// sample of n integers ranging from 0 to n - 1
	arma::vec ru = arma::randu( n );
	arma::vec id_tmp = arma::floor( n * ru );
	arma::uvec id1 = arma::conv_to<arma::uvec>::from(id_tmp);
	
	// second random sample of indexes
	// sample of n integers ranging from 0 to n - 1
	ru = arma::randu( n );
	id_tmp = arma::floor( n * ru );
	arma::uvec id2 = arma::conv_to<arma::uvec>::from(id_tmp);

	// get sample of x and y
	// since samples use diferent indexes, we are randomly sampling
	// from the set of x and y, 
	// that assumes the null hypothesis, no correlation between x and y
	arma::vec x_samp = x(id1);
	arma::vec y_samp = y(id2);

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
