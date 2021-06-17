#ifndef __RAND_TEST_HPP__
#define __RAND_TEST_HPP__

#include "gtest/gtest.h"

#include "../header/Rand.hpp"

TEST(RandTest, RandEvaluateAnyNumber) {
    Rand* test = new Rand() ;
    EXPECT_LT(0, 100);
}




#endif //__RAND_TEST_HPP__
