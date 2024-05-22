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

    // std::cout << "Q: " << q << " --- " << q * q << '\n'; 

    return res > 0 ? res : res + m;
}

bigint mod_mul_inv(bigint x, bigint m) {
    // inspired by https://www.extendedeuclideanalgorithm.com/calculator.php

    bigint n, b, q, r, t1, t2, t3;
    b = m; 
    r = x;
    t2 = 0;
    t3 = 1;

    do {
        n = b;
        b = r;
        q = n / b;
        r = n % b;
        t1 = t2;
        t2 = t3;
        t3 = t1 - t2*q;
        // std::cout << n << ' ' << b << ' ' << q << ' ' << r << ' ' << t1 << ' ' << t2 << ' ' << t3 << std::endl;
 
    } while (r != 0);

    if (t2 < 0) {
        t2 += m;
    }
    
    return t2;
}
