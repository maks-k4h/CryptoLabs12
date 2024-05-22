#ifndef LABS_PRIME
#define LABS_PRIME


#include "defs.hpp"

bool is_prime(bigint a);

bigint generate_prime(size_t n_bits, bool (criterion) (bigint) = is_prime);

bool miller_rabin_test(bigint n, size_t iters = 100);


#endif
