#include <gtest/gtest.h>
#include "../src/operations.hpp"

TEST(Operations, MultiplicationModTrivial) {
    ASSERT_EQ(multiply_mod(0, 0, 2), 0);
    ASSERT_EQ(multiply_mod(0, 10, 2), 0);
    ASSERT_EQ(multiply_mod(0, 1, 2), 0);
    ASSERT_EQ(multiply_mod(1, 1, 2), 1);
    ASSERT_EQ(multiply_mod(1, 1, 1), 0);
}

TEST(Operations, MultiplicationModStandard) {
    ASSERT_EQ(multiply_mod(4, 4, 16), 0);
    ASSERT_EQ(multiply_mod(25, 4, 13), 9);
    ASSERT_EQ(multiply_mod(37373737, 13131313, 999), 703);
}

TEST(Operations, PowModTrivial) {
    ASSERT_EQ(pow_mod(1, 0, 2), 1);
    ASSERT_EQ(pow_mod(1, 1, 2), 1);
    ASSERT_EQ(pow_mod(0, 0, 2), 1);
    ASSERT_EQ(pow_mod(0, 1, 2), 0);
    ASSERT_EQ(pow_mod(0, 1, 123), 0);
    ASSERT_EQ(pow_mod(123, 1, 2), 1);
}

TEST(Operations, PowModStandard) {
    ASSERT_EQ(pow_mod(4, 1, 9), 4);
    ASSERT_EQ(pow_mod(4, 2, 9), 7);
    ASSERT_EQ(pow_mod(2, 8, 15), 1);
    ASSERT_EQ(pow_mod(14, 13, 69), 11);
    ASSERT_EQ(pow_mod(9, 43, 57), 42);
}

TEST(Operations, PowModLarge) {
    ASSERT_EQ(pow_mod(449, 1121, 991), 881);
    ASSERT_EQ(pow_mod(312412332, 232132143, 2324211), 702525);
    ASSERT_EQ(pow_mod(561852391, 120975819, 1096472), 591007);
}

TEST(Operations, ModularMultiplicativeInverse) {
    ASSERT_EQ(mod_mul_inv(1, 2), 1);
    ASSERT_EQ(mod_mul_inv(3, 2), 1);
    ASSERT_EQ(mod_mul_inv(3, 26), 9);
    ASSERT_EQ(mod_mul_inv(1422, 123521), 67841);
    ASSERT_EQ(mod_mul_inv(125, 983), 810);
    ASSERT_EQ(mod_mul_inv(1157839, 2157839), 674452);
}
