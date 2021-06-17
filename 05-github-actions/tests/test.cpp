#include "../src/rectangle.cpp"

#include "gtest/gtest.h"


TEST(RectangleArea, ZeroAreaTEst) {
    Rectangle rect(0, 0);
    EXPECT_EQ( rect.area(), 0);
}

TEST(RectangleArea, PositiveAreaTest) {
    Rectangle rect(4, 5);
    EXPECT_EQ( rect.area(), 20 );
}

TEST(RectangleArea, NegativeAreaTest) {
    Rectangle rect(-4, 5);
    EXPECT_EQ( rect.area(), -20);
}

TEST(RectangleArea, DecimalAreaTest) {
    Rectangle rect(5.3134, 5.3134);
    EXPECT_EQ( rect.area(), 25);
}

TEST(RectanglePerimeter, ZeroPerimeterTest) {
    Rectangle rect(0, 0);
    EXPECT_EQ( rect.area(), 0);
}

TEST(RectanglePerimeter, PositivePerimeterTest) {
    Rectangle rect( 5, 20);
    EXPECT_EQ( rect.perimeter(),  50);
}

TEST(RectanglePerimeter, NegativePerimeterTest) {
    Rectangle rect( -5, 20);
    EXPECT_EQ( rect.perimeter(),  30);
}

TEST(RectanglePerimeter, DecimalPerimeterTest) {
    Rectangle rect(5.3134, 5.3134);
    EXPECT_EQ( rect.perimeter(), 20);
}

TEST(RectangleCtor, ZeroCtorTest)
{
   Rectangle rect( 0, 0 );
   EXPECT_EQ(rect.get_width(), 0);
   EXPECT_EQ(rect.get_height(),0);
}
     
TEST(RectangleCtor, PositiveCtorTest)
{
   Rectangle rect( 120, 30 );
   EXPECT_EQ(rect.get_width(),120);
   EXPECT_EQ(rect.get_height(),30);
}

TEST(RectangleCtor, NegativeCtorTest)
{
   Rectangle rect( -120, -30 );
   EXPECT_EQ(rect.get_width(), -120);
   EXPECT_EQ(rect.get_height(),-30);
}

TEST(RectangleCtor, DecimalCtorTest)
{
   Rectangle rect( 120.74, 30.87 );
   EXPECT_EQ(rect.get_width(),120);
   EXPECT_EQ(rect.get_height(),30);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}



