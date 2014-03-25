#include <Rcpp.h>
#include <cmath>
using namespace Rcpp;
extern "C" {
SEXP sampleSums(SEXP v_, SEXP Nsum_, SEXP k_) { 
    int Nsum(::Rf_asInteger(Nsum_)), k(::Rf_asInteger(k_));
    IntegerVector v(v_);
    int n(v.length());
    if (k <= 0 || n <= k) throw std::invalid_argument("Must have 0 < k < n");
    std::vector<int> inds(n);
    for (int i = 0; i < n; ++i) inds[i] = i;   // initialize to 0,...,n-1
    IntegerVector sums(Nsum);
    for (int j = 0; j < Nsum; ++j) {
        sums[j] = 0;  // probably not necessary - I think an IntegerVector is zeroed
        for (int i = 0; i < k; ++i) {
            int ind(i + floor(::unif_rand() * (n - i)));
            // swap the index at inds[i] with that at inds[ind]
            int vv = inds[ind];
            inds[ind] = inds[i];
            inds[i] = vv;
            sums[j] += v[vv];
        }
    }
    return wrap(sums);
}
}