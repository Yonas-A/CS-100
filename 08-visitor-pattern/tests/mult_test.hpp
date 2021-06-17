#ifndef __MULT_TEST_HPP__
#define __MULT_TEST_HPP__

#include "gtest/gtest.h"

#include "../header/Mult.hpp"

TEST(MultTest, MultEvaluateNonZero) {
    Mult* test = new Mult( new Op(8), new Op(1)) ;
    EXPECT_EQ(test->evaluate(), 8);
}

TEST(MultTest, MultEvaluateZero) {
    Mult* test = new Mult( new Op(8), new Op(0)) ;
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(MultTest, MultEvaluateNegativeInput) {
    Mult* test = new Mult( new Op(-23), new Op(-348)) ;
    EXPECT_EQ(test->evaluate(), 8004);
}

TEST(MultTest, MultEvaluateNegativeResult) {
    Mult* test = new Mult( new Op(-34), new Op(2)) ;
    EXPECT_EQ(test->evaluate(), -68);
}

TEST(MultTest, MultEvaluateDecimal) {
    Mult* test = new Mult( new Op(34.363), new Op(24.35)) ;
    EXPECT_NEAR(test->evaluate(), 836.739,  0.0001);
}

TEST(MultTest, MultEvaluateNegativeDecimal) {
    Mult* test = new Mult( new Op( -44.0), new Op(-56.003)) ;
    EXPECT_NEAR(test->evaluate(), 2464.132, 0.0001);
}

TEST(MultTest, MultStringifyNegativeDecimal) {
    Mult* test = new Mult( new Op( -44.0), new Op(-56.003)) ;
    EXPECT_EQ(test->stringify(), "-44.000000 * -56.003000");
}

TEST(MultTest, MultStringifyNonZero) {
    Mult* test = new Mult( new Op( 37), new Op(45)) ;
    EXPECT_EQ(test->stringify(), "37.000000 * 45.000000");
}

#endif //__MULT_TEST_HPP__
