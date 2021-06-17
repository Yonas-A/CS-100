#ifndef __ADD_TEST_HPP__
#define __ADD_TEST_HPP__

#include "gtest/gtest.h"

#include "../header/Add.hpp"

TEST(AddTest, AddEvaluateNonZero) {
    Add* test = new Add( new Op(8), new Op(1)) ;
    EXPECT_EQ(test->evaluate(), 9);
}

TEST(AddTest, AddEvaluateZero) {
    Add* test = new Add( new Op(7), new Op(-7)) ;
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(AddTest, AddEvaluateNegativeResult) {
    Add* test = new Add( new Op(35), new Op(-75)) ;
    EXPECT_EQ(test->evaluate(), -40) ;
}

TEST(AddTest, AddEvaluateNegativeDecimal) {
    Add* test = new Add( new Op( -44.0), new Op(-56.003)) ;
    EXPECT_EQ(test->evaluate(), -100.003000);
}

TEST(OpTest, AddStringifyNegativeDecimal) {
    Add* test = new Add( new Op( -44.0), new Op(-56.003)) ;
    EXPECT_EQ(test->stringify(), "-44.000000 + -56.003000");
}

TEST(OpTest, AddStringifyNonZero) {
    Add* test = new Add( new Op( 37), new Op(45)) ;
    EXPECT_EQ(test->stringify(), "37.000000 + 45.000000");
}

#endif //__ADD_TEST_HPP__
