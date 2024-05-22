#include "prime.hpp"
#include "myrand.hpp"
#include "operations.hpp"
#include <math.h>

bool is_prime(bigint a) {
    if (a < 2) 
        return false;
    if (a < 4) 
        return true;
    if (a % 2 == 0 || a % 3 == 0 || a % 5 == 0)
        return false;
    
    for ( bigint divisor = 5; divisor * divisor <= a; ++divisor) {
        if (a % divisor == 0)
            return false;
    }
    return true;
}

bigint generate_prime(size_t n_bits, bool (criterion) (bigint)) {
    bigint c = 1 << (n_bits - 1);  // random n-bit number
    for (size_t i = 0; i < n_bits - 1; ++i) {
        c += (rand() % 2) << i;
    }

    bigint n_min = 1 << (n_bits - 1);
    bigint n_max = (1 << n_bits) - 1;

    for (bigint r = 0; c - r >= n_min; ++r) {
        if (criterion(c - r)) return c - r;
    }
    for (bigint r = 0;; ++r) {
        if (criterion(c + r)) return c + r;
    }
    return 2;
}

bool miller_rabin_test(bigint n, size_t iters) {
    // false is a number is 100% not prime, true if a number is probably prime

    if (n < 2) 
        return false;
    if (n < 4) 
        return true;
    if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0)
        return false;

    for (size_t i = 1; i < iters; ++i) {
        bigint a = 1 + (randint() % (n - 1));
        if (pow_mod(a, n - 1, n) != 1)  // Fermat test first
            return false;

        bigint s = 1;  // a^(d*2^s) = a^(n-1)
        while (((n - 1) > (2 << s)) && (n - 1) % (2 << s) == 0)
            ++s;
        bigint d = (n - 1) / (1 << s);

        while (s > 0) {
            s -= 1;  // already checked for input s via Fermat test
            auto l = pow_mod(a, d * (1 << s), n);
            if (l != 1) {
                if (l == n-1) 
                    break;  // ok, the first element that is not 1 is -1; break
                return false;
            }
        }
    }
    return true;
}