#include <Rcpp.h>
// [[Rcpp::export]]
double sumRcpp(const Rcpp::NumericVector& x) {
    std::size_t n = x.size();
    double total = 0;
    if (n > 0) {
        for (std::size_t i = 0, k = n - 1; i < k; ++i, --k)
            total += x[i] + x[k];
        if (n % 2 == 1)
            total += x[n / 2];
    }
    return total;
}


#include <Rcpp.h>
// sumRcpp
double sumRcpp(const Rcpp::NumericVector& x);
RcppExport SEXP sourceCpp_1_sumRcpp(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Rcpp::NumericVector& >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(sumRcpp(x));
    return rcpp_result_gen;
END_RCPP
}
