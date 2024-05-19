#include "operations.hpp"

bigint multiply_mod(bigint a, bigint b, bigint m) {
    return ((a % m) * (b % m)) % m;
}

bigint pow_mod(bigint a, bigint pow, bigint m) {
    if (pow == 0) {
        return 1 % m;
    }
    if (pow == 1) {
        return a % m;
    }
    auto q = pow_mod(a, pow / 2, m);
    // a^n mod m == a^(n//2) * a^(n//2) * a^(n % 2) mod m
    bigint res = (((q * q) % m) * (pow % 2 ? (a % m) : 1)) % m;

    return res;
}
