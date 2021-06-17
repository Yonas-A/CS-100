#ifndef __VISITOR_TEST_HPP__
#define __VISITOR_TEST_HPP__

#include "gtest/gtest.h"

#include "../header/Add.hpp"
#include "../header/base.hpp"
#include "../header/Div.hpp"
#include "../header/Mult.hpp"
#include "../header/Op.hpp"
#include "../header/Pow.hpp"
#include "../header/Rand.hpp"
#include "../header/Sub.hpp"

TEST(VistorTest, VisitorAdd) {
    Base* test = new Add(new Op(8), new Op(2));
    PreorderIterator* it = new PreorderIterator(test);
    CountVisitor* visitor = new CountVisitor();
    it->first();

    EXPECT_EQ(visitor->add_count(), 0);
    EXPECT_EQ(visitor->div_count(), 0);
    EXPECT_EQ(visitor->mult_count(), 0);
    EXPECT_EQ(visitor->op_count(), 0);
    EXPECT_EQ(visitor->pow_count(), 0);
    EXPECT_EQ(visitor->sub_count(), 0);
}

TEST(VistorTest, VisitorDiv) {
    Base* test = new Div(new Op(8), new Op(2));
    PreorderIterator* it = new PreorderIterator(test);
    CountVisitor* visitor = new CountVisitor();
    it->first();

    while (!it->is_done()) {
        it->current()->accept(visitor);
        it->next();
    }
    EXPECT_EQ(visitor->add_count(), 0);
    EXPECT_EQ(visitor->div_count(), 0);
    EXPECT_EQ(visitor->mult_count(), 0);
    EXPECT_EQ(visitor->op_count(), 2);
    EXPECT_EQ(visitor->pow_count(), 0);
    EXPECT_EQ(visitor->sub_count(), 0);
}

TEST(VistorTest, VisitorMult) {
    Base* test = new Mult(new Op(8), new Op(2));
    PreorderIterator* it = new PreorderIterator(test);
    CountVisitor* visitor = new CountVisitor();
    it->first();

    while (!it->is_done()) {
        it->current()->accept(visitor);
        it->next();
    }
    EXPECT_EQ(visitor->add_count(), 0);
    EXPECT_EQ(visitor->div_count(), 0);
    EXPECT_EQ(visitor->mult_count(), 0);
    EXPECT_EQ(visitor->op_count(), 2);
    EXPECT_EQ(visitor->pow_count(), 0);
    EXPECT_EQ(visitor->sub_count(), 0);
}

TEST(VistorTest, VisitorSub) {
    Base* test = new Sub(new Op(8), new Op(2));
    PreorderIterator* it = new PreorderIterator(test);
    CountVisitor* visitor = new CountVisitor();
    it->first();

    while (!it->is_done()) {
        it->current()->accept(visitor);
        it->next();
    }
    EXPECT_EQ(visitor->add_count(), 0);
    EXPECT_EQ(visitor->div_count(), 0);
    EXPECT_EQ(visitor->mult_count(), 0);
    EXPECT_EQ(visitor->op_count(), 2);
    EXPECT_EQ(visitor->pow_count(), 0);
    EXPECT_EQ(visitor->sub_count(), 0);
}

TEST(VistorTest, VisitorExpression1) {
    Base* sub = new Sub(new Op(33), new Op(8));
    Base* add = new Add(sub, new Op(5));
    Base* mult = new Mult(new Op(0.49), new Op(10));
    Base* div = new Div(mult, new Op(7));
    Base* test = new Pow(add, div);
    Base* dummy = new Add(test, new Op(7));

    PreorderIterator* it = new PreorderIterator(dummy);
    CountVisitor* visitor = new CountVisitor();
    
    it->first();

    while (!it->is_done()) {
        it->current()->accept(visitor);
        it->next();
    }
    EXPECT_EQ(visitor->add_count(), 1);
    EXPECT_EQ(visitor->div_count(), 1);
    EXPECT_EQ(visitor->mult_count(), 1);
    EXPECT_EQ(visitor->op_count(), 7);
    EXPECT_EQ(visitor->pow_count(), 1);
    EXPECT_EQ(visitor->sub_count(), 1);
}

TEST(VistorTest, VisitorExpression2) {
    Base* sub = new Sub(new Op(33), new Op(8));
    Base* add = new Add(sub, new Op(5));
    Base* mult = new Mult(new Op(0.49), new Op(10));
    Base* add2 = new Add(mult, new Op(7));
    Base* test = new Pow(add, add2);
    Base* dummy = new Add( new Op(7), test);

    PreorderIterator* it = new PreorderIterator(dummy);
    CountVisitor* visitor = new CountVisitor();

    it->first();

    while (!it->is_done()) {
        it->current()->accept(visitor);
        it->next();
    }
    EXPECT_EQ(visitor->add_count(), 2);
    EXPECT_EQ(visitor->div_count(), 0);
    EXPECT_EQ(visitor->mult_count(), 1);
    EXPECT_EQ(visitor->op_count(), 7);
    EXPECT_EQ(visitor->pow_count(), 1);
    EXPECT_EQ(visitor->sub_count(), 1);
}

TEST(VistorTest, VisitorExpression3) {
    Base* pow = new Pow(new Op(5), new Op(3));
    Base* sub = new Sub(pow, new Op(2));
    Base* div = new Div(sub, new Op(7));
    Base* add = new Add(div, sub);
    Base* test = new Pow(add, div);
    Base* dummy = new Add(test, new Op(7));

    PreorderIterator* it = new PreorderIterator(dummy);
    CountVisitor* visitor = new CountVisitor();

    it->first();

    while (!it->is_done()) {
        it->current()->accept(visitor);
        it->next();
    }
    EXPECT_EQ(visitor->add_count(), 1);
    EXPECT_EQ(visitor->div_count(), 2);
    EXPECT_EQ(visitor->mult_count(), 0);
    EXPECT_EQ(visitor->op_count(), 12);
    EXPECT_EQ(visitor->pow_count(), 4);
    EXPECT_EQ(visitor->sub_count(), 3);
}

#endif //__VISITOR_TEST_HPP__
