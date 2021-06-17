#ifndef __DIV_TEST_HPP__
#define __DIV_TEST_HPP__

#include "gtest/gtest.h"

#include "../header/Div.hpp"
#include "../header/Op.hpp"

TEST(DivTest, DivEvaluateNonZero) {
    Div* test = new Div( new Op(8), new Op(1)) ;
    EXPECT_EQ(test->evaluate(), 8);
}

TEST(DivTest, DivEvaluateZero) {
    Div* test = new Div( new Op(0), new Op(8)) ;
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(DivTest, DivEvaluateNegativeInput) {
    Div* test = new Div( new Op(-20), new Op(5)) ;
    EXPECT_DOUBLE_EQ(test->evaluate(), -4.000000);
}

TEST(DivTest, DivEvaluateNegativeResult) {
    Div* test = new Div( new Op(-34), new Op(2)) ;
    EXPECT_EQ(test->evaluate(), -17);
}

TEST(DivTest, DivEvaluateDecimal) {
    Div* test = new Div( new Op(34.363), new Op(24.35)) ;
    EXPECT_DOUBLE_EQ(test->evaluate(), 1.4112114989733058); 
}

TEST(DivTest, DivEvaluateNegativeDecimal) {
    Div* test = new Div( new Op( -44.0), new Op(-56.003)) ;
    EXPECT_DOUBLE_EQ(test->evaluate(), 0.78567219613235006 );
}

TEST(DivTest, DivStringifyNegativeDecimal) {
    Div* test = new Div( new Op( -44.0), new Op(-56.003)) ;
    EXPECT_EQ(test->stringify(), "-44.000000 / -56.003000");
}

TEST(DivTest, DivStringifyNonZero) {
    Div* test = new Div( new Op( 37), new Op(45)) ;
    EXPECT_EQ(test->stringify(), "37.000000 / 45.000000");
}

#endif //__DIV_TEST_HPP__

