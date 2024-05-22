#ifndef LABS_OPERATIONS
#define LABS_OPERATIONS


#include "defs.hpp"


bigint multiply_mod(bigint a, bigint b, bigint m);

bigint pow_mod(bigint a, bigint pow, bigint m);

// modular multiplicative inverse
bigint mod_mul_inv(bigint x, bigint m);


#endif
