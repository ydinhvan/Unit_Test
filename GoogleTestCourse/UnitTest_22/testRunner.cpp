#include <iostream>
#include <gtest/gtest.h>
#include <vector>

#include "LibraryCode.hpp"

TEST(TestSuite, Test_Basic)
{
    // Arrange
    std::vector<int> inputVector{1, -2, 3, 4, 5, -6};

    // Act
    int count = countPositives(inputVector);

    // Assert
    ASSERT_EQ(4, count); 
}

TEST(TestSuite, Test_AllNegative)
{
    // Arrange
    std::vector<int> inputVector{-1, -2, -3, -4, -5, -6};

    // Act
    int count = countPositives(inputVector);

    // Assert
    ASSERT_EQ(4, count); 
    std::cout << "test pass" << std::endl;
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}