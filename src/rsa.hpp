#ifndef LABS_RSA
#define LABS_RSA

#include "defs.hpp"
#include "format.hpp"
#include <string>


class RSA {
public:
    struct PublicKey {
        bigint n;
        bigint e;

        operator std::string() { return std::string("PublicKey(n=") + as_base10(n) + ", e=" + as_base10(e) + ")"; }
    };
    struct PrivateKey {
        bigint d;
        bigint p;
        bigint q;

        operator std::string() { return std::string("PublicKey(p=") + as_base10(p) + ", q=" + as_base10(q) + ", d=" + as_base10(d) + ")"; }
    };

    void generate_keys(PublicKey &pub, PrivateKey &priv);

    bigint encrypt(bigint message, const PublicKey& pub);
    bigint decrypt(bigint cyphertext, const PublicKey& pub, const PrivateKey& priv);
};


#endif