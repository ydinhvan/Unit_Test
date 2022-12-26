#include <iostream>
#include <gtest/gtest.h>
#include <cctype>
#include <cstdlib>

#include "LibraryCode.hpp"


TEST(TestSuite, Test_Basic)
{
    // Arrange
    char inputString[] = "Hello World";
    
    // Act
    toUpper(inputString);

    // Assert
    ASSERT_EQ("HELLO WORLD", inputString);
    std::cout << "test pass" << std::endl;
}

TEST(TestSuite, Test_Basic1)
{
    // Arrange
    char inputString[] = "Hello World";
    
    // Act
    toUpper(inputString);

    // Assert
    ASSERT_STREQ("HELLO WORLD", inputString);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
