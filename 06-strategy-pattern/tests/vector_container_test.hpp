#ifndef __VECTORCONTAINER_TEST_HPP__
#define __VECTORCONTAINER_TEST_HPP__

#include "gtest/gtest.h"
#include <stdexcept>

#include "../src/VectorContainer.cpp"
#include "../header/Add.hpp"
#include "../header/Mult.hpp"
#include "../header/Sub.hpp"

TEST(VectorContainerTest, AddElement) {
    VectorContainer* test = new VectorContainer( ) ;
    Add* a = new Add(new Op(4), new Op(7) );
    test->add_element( a );
    ASSERT_EQ( test->size(), 1);

    testing::internal::CaptureStdout();
    test->print();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ( output, "4.000000 + 7.000000\n" );
}

TEST(VectorContainerTest, TestAt) {
    VectorContainer* test = new VectorContainer( ) ;
    Mult* a;
    for( int i = 0; i < 5 ; i++ )    {
        a = new Mult(new Op(2* i), new Op( 3* i ));
        test->add_element(a);
    }
    ASSERT_EQ( test->size(), 5);
    EXPECT_EQ( test->at(3)->evaluate(),54 );
}

TEST(VectorContainerTest, TestSwap) {
    VectorContainer* test = new VectorContainer( ) ;
    Mult* a;
    for( int i = 0; i < 5 ; i++ )    {
        a = new Mult(new Op(2* i), new Op( 3* i ));
        test->add_element(a);
    }
   // EXPECT_THROW( test->swap( 4, 6),std::exception);
}

TEST(VectorContainerTest, TestSize) {
    VectorContainer* test = new VectorContainer( ) ;
    Base* a;
    for( int i = 0; i < 15 ; i++ )    {
        a = new Sub(new Op(2* i), new Op( 3* i ));
        test->add_element(a);
    }

    a = new Mult(new Op(2), new Op(27) );
    EXPECT_EQ( test->size(), 15 );
}

#endif //__VECTORCONTAINER_TEST_HPP__


