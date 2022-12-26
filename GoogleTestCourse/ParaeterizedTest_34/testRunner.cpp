#include "LibraryCode.hpp"
#include <stdexcept>

#include <gmock/gmock.h>


/**
 * Problem: Validator (5,10)
 * value to test: 4, 5, 6, 7, 9, 10, 11
 * -> need more times to test: same body, different value
 * -> use: parameterized test
*/

class ValidatorFixture: public testing::TestWithParam<int>
{
 public:
    
 protected:
    Validator mValidator{5, 10};
};

TEST_P(ValidatorFixture, TestInRange)
{
    int param = GetParam();
    
    std::cout << "Param = " << param << "\n";
    bool isInside = mValidator.inRange(param);

    ASSERT_TRUE(isInside);
}

class ValidatorNegativeFixture: public testing::TestWithParam<int>
{
 public:
    
 protected:
    Validator mValidator{5, 10};
};

TEST_P(ValidatorNegativeFixture, TestInNotRange)
{
    int param = GetParam();
    
    std::cout << "Param (not in range)= " << param << "\n";
    bool isInside = mValidator.inRange(param);

    ASSERT_FALSE(isInside);
}

// INSTANTIATE_TEST_CASR_P(prefix, test_case_name, generator, __VA_ARGS__)
/**
 * prefix: not matter, just for naming purpose
 * test_case_name:
 * generator: generate test
 */
INSTANTIATE_TEST_CASE_P(InRangeTrue, ValidatorFixture, testing::Values(5,6,7,8,9,10));

INSTANTIATE_TEST_CASE_P(InRangeFalse, ValidatorNegativeFixture, testing::Values(4,59,-76,-9,100));

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}