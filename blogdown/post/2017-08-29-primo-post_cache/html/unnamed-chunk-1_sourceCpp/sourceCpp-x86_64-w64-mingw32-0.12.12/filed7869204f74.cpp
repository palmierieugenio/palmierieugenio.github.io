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
