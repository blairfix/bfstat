#include <RcppArmadillo.h>

// [[Rcpp::depends(RcppArmadillo)]]
// [[Rcpp::plugins(cpp11)]]
// [[Rcpp::export]]

arma::mat  boot_lm(
	arma::vec x, 
	arma::vec y, 
	int n_boot
	)
{


    // output matrix
    arma::mat output(n_boot, 2);


    // run boostrap
    //-------------------------------------------------------

    for( int boot = 0; boot < n_boot; boot++ ){

	int samp_size = x.size();

	arma::mat X(samp_size, 2);
	arma::vec Y(samp_size);

	std::random_device rd;  //obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_real_distribution<> dis(0, 1);

	// loop over x-y vectors and sample them
	for( int i = 0; i < samp_size; i++ ){

	    int index = samp_size * dis(gen);
	    X(i, 0) = 1;
	    X(i, 1) = x[index];
	    Y[i] = y[index];

	}
    
	// linear reagression
	arma::vec coef = arma::solve(X, Y); // coefficients of regression


	// put in output
	output(boot, 0) = coef[0];
	output(boot, 1) = coef[1];

    }

    return output;

}

