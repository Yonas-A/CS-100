#ifndef __FACTORY_TEST_HPP__
#define __FACTORY_TEST_HPP__

#include "gtest/gtest.h"

#include "../src/factory.cpp"

TEST(FactoryTest, FactoryAddition) {
    Factory* factory = new Factory();
    char* s[] = {"5", "+", "3", "+", "2"};
    int size = sizeof(s)/sizeof(s[0]);
    Base* test = factory->parse(s, size);
    EXPECT_EQ(test->evaluate(), 10);
}

TEST(FactoryTest, FactorySub) {
    Factory* factory = new Factory();
    char* s[] = {"5", "-", "3", "-", "2"};
    int size = sizeof(s)/sizeof(s[0]);
    Base* test = factory->parse(s, size);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(FactoryTest, FactoryAddSub) {
    Factory* factory = new Factory();
    char* s[] = {"5", "+", "3", "-", "2"};
    int size = sizeof(s)/sizeof(s[0]);
    Base* test = factory->parse(s, size);
    EXPECT_EQ(test->evaluate(), 6);
}


TEST(FactoryTest, FactoryDiv) {
    Factory* factory = new Factory();
    char* s[] = {"5", "/", "3", "/", "2"};
    int size = sizeof(s)/sizeof(s[0]);
    Base* test = factory->parse(s, size);
    EXPECT_DOUBLE_EQ(test->evaluate(),  0.83333333333333337 );
}

TEST(FactoryTest, FactoryMult) {
    Factory* factory = new Factory();
    char* s[] = {"5", "*", "3", "*", "2"};
    int size = sizeof(s)/sizeof(s[0]);
    Base* test = factory->parse(s, size);
    EXPECT_EQ(test->evaluate(), 30);
}

TEST(FactoryTest, FactoryPow) {
    Factory* factory = new Factory();
    char* s[] = {"5", "**", "3", "**", "2"};
    int size = sizeof(s)/sizeof(s[0]);
    Base* test = factory->parse(s, size);
    EXPECT_EQ(test->evaluate(), 15625);
}

TEST(FactoryTest, FactoryExpression1) {
    Factory* factory = new Factory();
    char* s[] = {"5", "**", "3", "+", "2"};
    int size = sizeof(s)/sizeof(s[0]);
    Base* test = factory->parse(s, size);
    EXPECT_EQ(test->evaluate(), 127);
}


TEST(FactoryTest, FactoryExpression2) {
    Factory* factory = new Factory();
    char* s[] = {"5", "*", "3", "+", "2"};
    int size = sizeof(s)/sizeof(s[0]);
    Base* test = factory->parse(s, size);
    EXPECT_EQ(test->evaluate(), 17);
}

TEST(FactoryTest, FactoryExpression3) {
    Factory* factory = new Factory();
    char* s[] = {"5", "+", "3", "*", "2"};
    int size = sizeof(s)/sizeof(s[0]);
    Base* test = factory->parse(s, size);
    EXPECT_EQ(test->evaluate(), 16);
}


TEST(FactoryTest, FactoryExpression4) {
    Factory* factory = new Factory();
    char* s[] = {"5", "/", "3", "*", "2", "-", "3.0"};
    int size = sizeof(s)/sizeof(s[0]);
    Base* test = factory->parse(s, size);
    EXPECT_DOUBLE_EQ(test->evaluate(),0.33333333333333348);
}

TEST(FactoryTest, FactoryExpression5) {
    Factory* factory = new Factory();
    char* s[] = {"5", "**", "3", "-", "2", "/", "7", "+" , "25"};
    int size = sizeof(s)/sizeof(s[0]);
    Base* test = factory->parse(s, size);
    EXPECT_DOUBLE_EQ(test->evaluate(),42.571428571428569); 
}

TEST(FactoryTest, FactoryExpression6) {
    Factory* factory = new Factory();
    char* s[] = {"455.3", "/", "3", "-", "1", "/", "7", "+" , "25"};
    int size = sizeof(s)/sizeof(s[0]);
    Base* test = factory->parse(s, size);
    EXPECT_DOUBLE_EQ(test->evaluate(),46.538095238095238);
}

TEST(FactoryTest, FactoryExpressionInvalid) {
    Factory* factory = new Factory();
    char* s[] = {"45", "/", "3", "-", "&", "/", "7", "+" , "25"};
    int size = sizeof(s)/sizeof(s[0]);
    Base* test = factory->parse(s, size);
    EXPECT_TRUE( test == nullptr);
}

TEST(FactoryTest, FactoryExpression5String) {
    Factory* factory = new Factory();
    char* s[] = {"5", "**", "3", "-", "2", "/", "7", "+" , "25"};
    int size = sizeof(s)/sizeof(s[0]);
    Base* test = factory->parse(s, size);
    EXPECT_EQ(test->stringify(), "5.000000 ** 3.000000 - 2.000000 / 7.000000 + 25.000000" ); 
}

TEST(FactoryTest, FactoryExpression6String) {
    Factory* factory = new Factory();
    char* s[] = {"455.3", "/", "3", "-", "2", "/", "7", "+" , "25"};
    int size = sizeof(s)/sizeof(s[0]);
    Base* test = factory->parse(s, size);
    EXPECT_EQ(test->stringify(), "455.300000 / 3.000000 - 2.000000 / 7.000000 + 25.000000"); 
}

#endif // __FACTORY_TEST_HPP__
