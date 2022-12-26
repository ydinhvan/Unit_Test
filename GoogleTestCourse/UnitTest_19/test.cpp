#include <gtest/gtest.h>
#include "LibraryCode.hpp"

TEST(TestSuiteSample, TestSample)
{
    int sum_test = sum(2, 4);
    ASSERT_EQ(6, sum_test);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}