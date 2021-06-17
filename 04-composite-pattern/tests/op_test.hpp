#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "../header/Op.hpp"

TEST(OpTest, OpEvaluateNonZero) {
    Op* test = new Op(8);
    EXPECT_EQ(test->evaluate(), 8);
}

TEST(OpTest, OpEvaluateNegativeDecimal) {
    Op* test = new Op(-3.0);
    EXPECT_EQ(test->evaluate() , -3.0);
}

TEST(OpTest, OpEvaluatePI) {
    Op* test = new Op(3.1415674);
    EXPECT_EQ(test->evaluate() ,3.1415674);
}

TEST(OpTest, OpStringifyNonZero) {
    Op* test = new Op(36);
    EXPECT_EQ(test->stringify(), "36.000000");
}

TEST(OpTest, OpStringifyNegativeDecimal) {
    Op* test = new Op(-3.036);
    EXPECT_EQ(test->stringify(), "-3.036000");
}

#endif //__OP_TEST_HPP__
