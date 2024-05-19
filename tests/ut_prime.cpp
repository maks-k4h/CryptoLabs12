#include <gtest/gtest.h>
#include "../src/prime.hpp"

TEST(Prime, IsPrime) {
    ASSERT_FALSE(is_prime(0));
    ASSERT_FALSE(is_prime(1));
    ASSERT_FALSE(is_prime(13*97));
    ASSERT_FALSE(is_prime(8191*8191));
    ASSERT_TRUE(is_prime(2));
    ASSERT_TRUE(is_prime(3));
    ASSERT_TRUE(is_prime(97));
    ASSERT_TRUE(is_prime(2147483647));
}

TEST(Prime, GenerateNBitPrime) {
    auto m = generate_prime(2);
    ASSERT_TRUE(m == 2 || m == 3);

    m = generate_prime(4);
    ASSERT_TRUE(is_prime(m) && (0b1000 <= m <= 0b1111));

    m = generate_prime(24);
    ASSERT_TRUE(is_prime(m) && ((1 << 23) <= m <= (1 << 24) - 1));

    m = generate_prime(25);
    ASSERT_TRUE(is_prime(m) && ((1 << 24) <= m <= (1 << 25) - 1));
}

TEST(Prime, MillerRabin) {
    // false in trivial cases
    ASSERT_FALSE(miller_rabin_test(1, 0.001));
    ASSERT_FALSE(miller_rabin_test(4, 0.001));

    // true for prime numbers
    ASSERT_TRUE(miller_rabin_test(2, 0.001));
    ASSERT_TRUE(miller_rabin_test(3, 0.001));
    ASSERT_TRUE(miller_rabin_test(97, 0.001));
    ASSERT_TRUE(miller_rabin_test(2147483647, 0.001));
}