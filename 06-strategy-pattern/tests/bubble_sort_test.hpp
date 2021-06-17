#ifndef __BUBBLE_SORT_TEST_HPP__
#define __BUBBLE_SORT_TEST_HPP__

#include "gtest/gtest.h"

#include "../header/Add.hpp"
#include "../header/Mult.hpp"
#include "../header/Sub.hpp"
#include "../header/BubbleSort.hpp"
#include "../header/VectorContainer.hpp"
#include "../header/ListContainer.hpp"

TEST(SortTestSet2, BubbleSortVectorContainerTest) {
    Op* seven = new Op(7);
    Op* four = new Op(4);
    Mult* TreeA = new Mult(seven, four);

    Op* three = new Op(3);
    Op* two = new Op(2);
    Add* TreeB = new Add(three, two);

    Op* ten = new Op(10);
    Op* six = new Op(6);
    Sub* TreeC = new Sub(ten, six);

    VectorContainer* container = new VectorContainer();
    container->add_element(TreeA);
    container->add_element(TreeB);
    container->add_element(TreeC);

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 28);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 4);

    container->set_sort_function(new BubbleSort());
    container->sort();

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 4);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 28);
}

TEST(SortTestSet2, BubbleSortVectorContainerTest2) {
    Add* TreeA  = new Add(new Op(6), new Op(2));
    Div* TreeB  = new Div(new Op(6), new Op(2));
    Mult* TreeC = new Mult(new Op(6), new Op(2));
    Op* TreeD   = new Op(6);
    Pow* TreeE  = new Pow(new Op(6), new Op(2));
    Sub* TreeF  = new Sub(new Op(6), new Op(2));
    // Rand* TreeG = new Rand();

    VectorContainer* container = new VectorContainer();
    container->add_element(TreeA);
    container->add_element(TreeB);
    container->add_element(TreeC);
    container->add_element(TreeD);
    container->add_element(TreeE);
    container->add_element(TreeF);
    // container->add_element(TreeG);

    ASSERT_EQ(container->size(), 6);
    EXPECT_EQ(container->at(0)->evaluate(), 8);
    EXPECT_EQ(container->at(1)->evaluate(), 3);
    EXPECT_EQ(container->at(2)->evaluate(), 12);
    EXPECT_EQ(container->at(3)->evaluate(), 6);
    EXPECT_EQ(container->at(4)->evaluate(), 36);
    EXPECT_EQ(container->at(5)->evaluate(), 4);
    // EXPECT_EQ(container->at(6)->evaluate(), 4);

    container->set_sort_function(new BubbleSort());
    container->sort();

    ASSERT_EQ(container->size(), 6);
    EXPECT_EQ(container->at(0)->evaluate(), 3);
    EXPECT_EQ(container->at(1)->evaluate(), 4);
    EXPECT_EQ(container->at(2)->evaluate(), 6);
    EXPECT_EQ(container->at(3)->evaluate(), 8);
    EXPECT_EQ(container->at(4)->evaluate(), 12);
    EXPECT_EQ(container->at(5)->evaluate(), 36);
}

TEST(SortTestSet2, BubbleSortListContainerTest) {
    Op* seven = new Op(7);
    Op* four = new Op(4);
    Mult* TreeA = new Mult(seven, four);

    Op* three = new Op(3);
    Op* two = new Op(2);
    Add* TreeB = new Add(three, two);

    Op* ten = new Op(10);
    Op* six = new Op(6);
    Sub* TreeC = new Sub(ten, six);

    ListContainer* container = new ListContainer();
    container->add_element(TreeA);
    container->add_element(TreeB);
    container->add_element(TreeC);

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 28);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 4);

    container->set_sort_function(new BubbleSort());
    container->sort();

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 4);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 28);
}

TEST(SortTestSet2, SelectionSortListContainerTest2) {
    Add* TreeA  = new Add(new Op(6), new Op(2));
    Div* TreeB  = new Div(new Op(6), new Op(2));
    Mult* TreeC = new Mult(new Op(6), new Op(2));
    Op* TreeD   = new Op(6);
    Pow* TreeE  = new Pow(new Op(6), new Op(2));
    Sub* TreeF  = new Sub(new Op(6), new Op(2));
    // Rand* TreeG = new Rand();

    ListContainer* container = new ListContainer();
    container->add_element(TreeA);
    container->add_element(TreeB);
    container->add_element(TreeC);
    container->add_element(TreeD);
    container->add_element(TreeE);
    container->add_element(TreeF);
    // container->add_element(TreeG);

    ASSERT_EQ(container->size(), 6);
    EXPECT_EQ(container->at(0)->evaluate(), 8);
    EXPECT_EQ(container->at(1)->evaluate(), 3);
    EXPECT_EQ(container->at(2)->evaluate(), 12);
    EXPECT_EQ(container->at(3)->evaluate(), 6);
    EXPECT_EQ(container->at(4)->evaluate(), 36);
    EXPECT_EQ(container->at(5)->evaluate(), 4);
    // EXPECT_EQ(container->at(6)->evaluate(), 4);

    container->set_sort_function(new BubbleSort());
    container->sort();

    ASSERT_EQ(container->size(), 6);
    EXPECT_EQ(container->at(0)->evaluate(), 3);
    EXPECT_EQ(container->at(1)->evaluate(), 4);
    EXPECT_EQ(container->at(2)->evaluate(), 6);
    EXPECT_EQ(container->at(3)->evaluate(), 8);
    EXPECT_EQ(container->at(4)->evaluate(), 12);
    EXPECT_EQ(container->at(5)->evaluate(), 36);
}

#endif //__BUBBLE_SORT_TEST_HPP__

