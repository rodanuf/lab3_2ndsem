#include <gtest/gtest.h>
#include "../types_headers/complex.hpp"

TEST(test_complex, basic_constructor) {
    complex c;
    EXPECT_DOUBLE_EQ(c.get_real(), 0.0);
    EXPECT_DOUBLE_EQ(c.get_imag(), 0.0);
}

TEST(test_complex, constructor_with_real) {
    complex c(3.5);
    EXPECT_DOUBLE_EQ(c.get_real(), 3.5);
    EXPECT_DOUBLE_EQ(c.get_imag(), 0.0);
}

TEST(test_complex, constructor_with_real_imag) {
    complex c(2.0, -1.5);
    EXPECT_DOUBLE_EQ(c.get_real(), 2.0);
    EXPECT_DOUBLE_EQ(c.get_imag(), -1.5);
}

TEST(test_complex, operator_plus) {
    complex a(1.0, 2.0);
    complex b(3.0, -1.0);
    complex c = a + b;
    EXPECT_DOUBLE_EQ(c.get_real(), 4.0);
    EXPECT_DOUBLE_EQ(c.get_imag(), 1.0);
}

TEST(test_complex, operator_minus) {
    complex a(5.0, 3.0);
    complex b(2.0, 1.0);
    complex c = a - b;
    EXPECT_DOUBLE_EQ(c.get_real(), 3.0);
    EXPECT_DOUBLE_EQ(c.get_imag(), 2.0);
}

TEST(test_complex, operator_multiply) {
    complex a(1.0, 2.0);
    complex b(3.0, 4.0);
    complex c = a * b;
    EXPECT_DOUBLE_EQ(c.get_real(), -5.0);
    EXPECT_DOUBLE_EQ(c.get_imag(), 10.0);
}

TEST(test_complex, operator_divide) {
    complex a(1.0, 2.0);
    complex b(1.0, 1.0);
    complex c = a / b;
    EXPECT_DOUBLE_EQ(c.get_real(), 1.5);
    EXPECT_DOUBLE_EQ(c.get_imag(), 0.5);
}

TEST(test_complex, operator_equality) {
    complex a(1.0, 2.0);
    complex b(1.0, 2.0);
    complex c(1.0, 2.1);
    EXPECT_TRUE(a == b);
    EXPECT_FALSE(a == c);
}

TEST(test_complex, operator_inequality) {
    complex a(1.0, 2.0);
    complex b(1.1, 2.0);
    complex c(1.0, 2.0);
    EXPECT_TRUE(a != b);
    EXPECT_FALSE(a != c);
}

TEST(test_complex, operator_less_than) {
    complex a(1.0, 1.0);
    complex b(2.0, 0.0);
    EXPECT_TRUE(a < b);
    EXPECT_FALSE(b < a);
}

TEST(test_complex, operator_greater_than) {
    complex a(3.0, 4.0);  // modulus = 5.0
    complex b(1.0, 1.0);  // modulus ≈ 1.414
    EXPECT_TRUE(a > b);
    EXPECT_FALSE(b > a);
}

TEST(test_complex, get_modulus) {
    complex c(3.0, 4.0);
    EXPECT_DOUBLE_EQ(c.get_modulus(), 5.0);
}

TEST(test_complex, set_real_imag) {
    complex c;
    c.set_real(2.5);
    c.set_imag(-1.5);
    EXPECT_DOUBLE_EQ(c.get_real(), 2.5);
    EXPECT_DOUBLE_EQ(c.get_imag(), -1.5);
}

TEST(test_complex, input_output_operators) {
    std::stringstream ss;
    complex c(1.5, -2.5);
    ss << c;
    EXPECT_EQ(ss.str(), "1.5-2.5i");
    complex c2;
    ss >> c2;
    EXPECT_DOUBLE_EQ(c2.get_real(), 1.5);
    EXPECT_DOUBLE_EQ(c2.get_imag(), -2.5);
}

TEST(test_complex, special_output_cases) {
    std::stringstream ss;
    complex c1(0.0, 1.0);
    ss << c1;
    EXPECT_EQ(ss.str(), "0 + 1i");
    ss.str("");
    complex c2(1.0, -1.0);
    ss << c2;
    EXPECT_EQ(ss.str(), "1-1i");
    ss.str("");
    complex c3(2.0, 0.0);
    ss << c3;
    EXPECT_EQ(ss.str(), "2");
}