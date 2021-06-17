#ifndef __ITERATOR_TEST_HPP__
#define __ITERATOR_TEST_HPP__

#include "gtest/gtest.h"

#include "../header/Add.hpp"
#include "../header/Div.hpp"
#include "../header/Mult.hpp"
#include "../header/Op.hpp"
#include "../header/Pow.hpp"
#include "../header/Sub.hpp"

#include "../header/iterator.hpp"


TEST(IteratorTest, IterateExpression1) {
    Base* test = new Add(new Op(3), new Mult(new Op(4), new Op(5)));
    Iterator* it = test->create_iterator();

    EXPECT_EQ(it->current()->stringify(), "3.000000");
    EXPECT_EQ(test->get_left()->stringify(), "3.000000");
    EXPECT_EQ(test->get_right()->stringify(), "4.000000 * 5.000000");
}

TEST(IteratorTest, IterateExpression2) {
    Base* test = new Add(new Mult(new Op(4), new Op(5)), new Op(3));
    Iterator* it = test->create_iterator();

    EXPECT_EQ(it->current()->stringify(),"4.000000 * 5.000000");
    EXPECT_EQ(test->get_left()->stringify(),"4.000000 * 5.000000");
    EXPECT_EQ(test->get_right()->stringify(), "3.000000");
}

TEST(IteratorTest, IterateExpression3) {
    Base* sub = new Sub(new Op(4), new Op(5));
    Base* mult = new Mult(new Op(4), new Op(5));
    Base* test = new Add( sub, mult);
    Iterator* it = test->create_iterator();

    EXPECT_EQ(it->current()->stringify(), "4.000000 - 5.000000");

    if( !it->is_done() )
        it->next();
    EXPECT_EQ(it->current()->stringify(), "4.000000 * 5.000000");
    EXPECT_EQ(test->get_left()->stringify(),"4.000000 - 5.000000");
}

TEST(IteratorTest, IteratorExpression4) {
    Base* sub = new Sub(new Op(33), new Op(8));
    Base* add = new Add(sub, new Op(5));
    Base* mult = new Mult(new Op(0.49), new Op(10));
    Base* div = new Div(mult, new Op(7));
    Base* test = new Pow(add, div);

    Iterator* it = test->create_iterator();
    EXPECT_EQ(it->current()->stringify(), "33.000000 - 8.000000 + 5.000000");
    EXPECT_EQ(it->current()->get_left()->stringify(), "33.000000 - 8.000000");
    EXPECT_EQ(it->current()->get_right()->stringify(), "5.000000");
}

TEST(IteratorTest, IteratorExpression5) {
    Base* sub = new Sub(new Op(33), new Op(8));
    Base* add = new Add(sub, new Op(5));
    Base* mult = new Mult(new Op(0.49), new Op(10));
    Base* div = new Div(mult, new Op(7));
    Base* test = new Pow(add, div);

    Iterator* it = test->create_iterator();
    it->next();
    EXPECT_EQ(it->current()->stringify(), "0.490000 * 10.000000 / 7.000000");
    EXPECT_EQ(it->current()->get_left()->stringify(), "0.490000 * 10.000000");
    EXPECT_EQ(it->current()->get_right()->stringify(), "7.000000");
}

TEST(IteratorTest, IteratorExpression6) {
    Base* test = new Pow(new Op(64), new Op(2));

    Iterator* it = test->create_iterator();
    EXPECT_EQ(test->stringify(), "64.000000 ** 2.000000");
    EXPECT_EQ(it->current()->stringify(), "64.000000" );
    EXPECT_TRUE(it->current()->get_left() == nullptr);
    EXPECT_TRUE(it->current()->get_right() == nullptr);
}

#endif //__ITERATOR_TEST_HPP__

