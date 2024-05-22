#include <iostream>

#include "src/rsa.hpp"
#include "src/format.hpp"

int main() {
    bigint message = 777;

    std::cout << "Alice wants to send message '" << message << "'\n";

    std::cout << "Alice generates a pair of keys...\n";
    RSA ctx;
    RSA::PublicKey pub;
    RSA::PrivateKey priv;
    ctx.generate_keys(pub, priv);
    std::cout << "Alice's public key: " << std::string(pub) << '\n';
    std::cout << "Alice's private key: " << std::string(priv) << '\n';

    std::cout << "Alice encrypts her message...\n";
    bigint ciphertext = ctx.encrypt(message, pub);
    std::cout << "ciphertext: " << ciphertext << '\n';

    std::cout << "Alice passes ciphertext and public key to Bob...\n";
    // magic...

    std::cout << "Bob decrypts the ciphertext...\n";
    bigint decrypted_message = ctx.decrypt(ciphertext, pub, priv);
    std::cout << "Decrypted message: '" << decrypted_message << "'\n";
}
