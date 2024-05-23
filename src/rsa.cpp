#include "rsa.hpp"
#include "prime.hpp"
#include "myrand.hpp"
#include "operations.hpp"
#include <numeric>


RSA::RSA(size_t nbits)
: nbits_(nbits)
{
}


void RSA::generate_keys(RSA::PublicKey &pub, RSA::PrivateKey &priv) {
    auto criterion = [](bigint a) {
        return miller_rabin_test(a, 100);
    };

    auto p = generate_prime(nbits_, criterion);
    auto q = p;
    while (p == q) {
        q = generate_prime(nbits_, criterion);
    }

    auto carmichael_num = std::lcm(p - 1, q - 1);

    bigint e = 65537;  // common practice

    bigint d = mod_mul_inv(e, carmichael_num);

    // set keys
    pub.n = p * q;
    pub.e = e;

    priv.d = d;
    priv.p = p;
    priv.q = q;
}

bigint RSA::encrypt(bigint message, const RSA::PublicKey& pub) {
    return pow_mod(message, pub.e, pub.n);
}

bigint RSA::decrypt(bigint ciphertext, const RSA::PublicKey& pub, const RSA::PrivateKey& priv) {
    return pow_mod(ciphertext, priv.d, pub.n);
}

bigint get_hash(bigint message, size_t bits = 16) {
    // Rabin hash function
    auto p1 = generate_prime(bits / 2);
    auto p2 = generate_prime(bits / 2);
    auto n = p1 * p2;
    return pow_mod(message, 2, n);
}

bigint RSA::sign(bigint message, const RSA::PublicKey &pub, const RSA::PrivateKey &priv) {
    bigint hash = get_hash(message);
    return pow_mod(hash, priv.d, pub.n);
}

bool RSA::verify(bigint message, bigint signature, const RSA::PublicKey &pub) {
    auto hash = get_hash(message);
    auto dec_hash = pow_mod(signature, pub.e, pub.n);
    return hash == dec_hash;
}
