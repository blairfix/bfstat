// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// boot_cor
arma::rowvec boot_cor(arma::vec& x, arma::vec& y, double n_boot, double conf);
RcppExport SEXP _bfstat_boot_cor(SEXP xSEXP, SEXP ySEXP, SEXP n_bootSEXP, SEXP confSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::vec& >::type x(xSEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type y(ySEXP);
    Rcpp::traits::input_parameter< double >::type n_boot(n_bootSEXP);
    Rcpp::traits::input_parameter< double >::type conf(confSEXP);
    rcpp_result_gen = Rcpp::wrap(boot_cor(x, y, n_boot, conf));
    return rcpp_result_gen;
END_RCPP
}
// boot_cor_null
arma::rowvec boot_cor_null(arma::vec& x, arma::vec& y, double n_boot, double conf);
RcppExport SEXP _bfstat_boot_cor_null(SEXP xSEXP, SEXP ySEXP, SEXP n_bootSEXP, SEXP confSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::vec& >::type x(xSEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type y(ySEXP);
    Rcpp::traits::input_parameter< double >::type n_boot(n_bootSEXP);
    Rcpp::traits::input_parameter< double >::type conf(confSEXP);
    rcpp_result_gen = Rcpp::wrap(boot_cor_null(x, y, n_boot, conf));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_bfstat_boot_cor", (DL_FUNC) &_bfstat_boot_cor, 4},
    {"_bfstat_boot_cor_null", (DL_FUNC) &_bfstat_boot_cor_null, 4},
    {NULL, NULL, 0}
};

RcppExport void R_init_bfstat(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
