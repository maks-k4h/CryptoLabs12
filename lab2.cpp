#include <iostream>
#include <chrono>

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


    std::cout << std::endl;
    // compare RSA speed based relative to binary size of prime numbers
    for (size_t nbits = 4; nbits < 17; ++nbits) {

        long long microseconds = 0;
        size_t n = 0;
        
        for (size_t i = 0; i < 50; ++i) {
            RSA test_ctx(nbits);    
            RSA::PublicKey test_pub;
            RSA::PrivateKey test_priv;

            auto start = std::chrono::high_resolution_clock::now();
            test_ctx.generate_keys(test_pub, test_priv);
            ciphertext = test_ctx.encrypt(13, test_pub);
            test_ctx.decrypt(ciphertext, test_pub, test_priv);
            auto end = std::chrono::high_resolution_clock::now();

            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            microseconds += duration.count();
            ++n;
        }
        std::cout << "Mean duration for " << nbits << " bits is  " << microseconds / n << " nsec." << std::endl;
    }

}
