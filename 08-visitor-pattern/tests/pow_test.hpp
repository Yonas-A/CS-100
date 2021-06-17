#ifndef __POW_TEST_HPP__
#define __POW_TEST_HPP__

#include "gtest/gtest.h"

#include "../header/Pow.hpp"

TEST(PowTest, PowEvaluateNonZero) {
    Pow* test = new Pow( new Op(8), new Op(1)) ;
    EXPECT_EQ(test->evaluate(), 8);
}

TEST(PowTest, PowEvaluateZero) {
    Pow* test = new Pow( new Op(8), new Op(0)) ;
    EXPECT_EQ(test->evaluate(), 1);
}

TEST(PowTest, PowEvaluateNegativeInput) {
    Pow* test = new Pow( new Op(-2), new Op(-4)) ;
    EXPECT_EQ(test->evaluate(), 0.0625);
}

TEST(PowTest, PowEvaluateNegativeResult) {
    Pow* test = new Pow( new Op(-34), new Op(3));
    EXPECT_EQ(test->evaluate(),-39304);
}

TEST(PowTest, PowEvaluateDecimal) {
    Pow* test = new Pow( new Op(34.353), new Op(0.35) );
    EXPECT_NEAR(test->evaluate(), 3.448161,  0.0001);
}

TEST(PowTest, PowEvaluateNegativeDecimal) {
    Pow* test = new Pow( new Op( -3), new Op(-3)) ;
    EXPECT_NEAR(test->evaluate(), -0.037037, 0.00001);
}

TEST(PowTest, PowStringifyNegativeDecimal) {
    Pow* test = new Pow( new Op( -44.0), new Op(-56.003)) ;
    EXPECT_EQ(test->stringify(), "-44.000000 ** -56.003000");
}

TEST(PowTest, PowStringifyNonZero) {
    Pow* test = new Pow( new Op( 37), new Op(45)) ;
    EXPECT_EQ(test->stringify(), "37.000000 ** 45.000000");
}

#endif //__POW_TEST_HPP__
