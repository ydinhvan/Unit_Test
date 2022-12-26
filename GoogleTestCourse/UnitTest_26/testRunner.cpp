#include "LibraryCode.hpp"
#include <gtest/gtest.h>


TEST(testSuit, Test_Negative)
{
    double inputValue = -9;

    // check message of runtime_error with throw 
    ASSERT_THROW(mySqrt(inputValue),std::runtime_error);
}

TEST(testSuit, Test_Positive)
{
    double inputValue = 9;

    ASSERT_NO_THROW(mySqrt(inputValue));   // check no message thrown
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}