#ifndef __SUB_TEST_HPP__
#define __SUB_TEST_HPP__

#include "gtest/gtest.h"

#include "../header/Sub.hpp"
#include "../header/Op.hpp"

TEST(SubTest, SubEvaluateNonZero) {
    Sub* test = new Sub( new Op(8), new Op(1)) ;
    EXPECT_EQ(test->evaluate(), 7);
}

TEST(SubTest, SubEvaluateZero) {
   Sub* test = new Sub( new Op(8), new Op(8)) ;
   EXPECT_EQ(test->evaluate(), 0);
}

TEST(SubTest, SubEvaluateNegativeInput) {
   Sub* test = new Sub( new Op(-23), new Op(-348)) ;
   EXPECT_EQ(test->evaluate(), 325);
}

TEST(SubTest, SubEvaluateNegativeResult) {
   Sub* test = new Sub( new Op(-34), new Op(-2)) ;
   EXPECT_EQ(test->evaluate(), -32);
}

TEST(SubTest, SubEvaluateDecimal) {
   Sub* test = new Sub( new Op(34.353), new Op(24.35) ) ;
   EXPECT_EQ(test->evaluate(), 10.003 );
}

TEST(SubTest, SubEvaluateNegativeDecimal) {
   Sub* test = new Sub( new Op( -44.0), new Op(-56.003)) ;
   EXPECT_EQ(test->evaluate(), 12.003000);
}

TEST(SubTest, SubStringifyNegativeDecimal) {
    Sub* test = new Sub( new Op( -44.0), new Op(-56.003)) ;
    EXPECT_EQ(test->stringify(), "-44.000000 - -56.003000");
}

TEST(SubTest, SubStringifyNonZero) {
    Sub* test = new Sub( new Op( 37), new Op(45)) ;
    EXPECT_EQ(test->stringify(), "37.000000 - 45.000000");
}


#endif //__SUB_TEST_HPP__
