#include <RcppArmadillo.h>

// [[Rcpp::depends(RcppArmadillo)]]
// [[Rcpp::plugins(cpp11)]]
// [[Rcpp::export]]

arma::vec  boot_lm(
	arma::vec x, 
	arma::vec span, 
	int n
	)
{

    // lm vectors
    int index;          
    arma::mat X(n, 2); 
    arma::vec y(n);
    
    // rn seed
    std::random_device r;  
    std::mt19937 gen( r() ); 
    std::uniform_real_distribution<> dis(0, 1);

    // boostrap sample
    for(int i = 0; i < n; i++){

	index = n*dis(gen) ;

	X(i, 0) = 1;
	X(i, 1) = x[index];

	y[i] = span[index];

    }

    // coefficients of regression
    arma::vec coef = arma::solve(X, y);

    return coef;

}

