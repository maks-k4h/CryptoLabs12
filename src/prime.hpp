#include "defs.hpp"

bool is_prime(bigint a);

bigint generate_prime(size_t n_bits);

bool miller_rabin_test(bigint n, double p);
