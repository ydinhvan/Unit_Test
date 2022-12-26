#include <iostream>
#include <gtest/gtest.h>
#include <vector>

#include "LibraryCode.hpp"

#include <gmock/gmock.h>

TEST(AccountTest, TestEmptyAccount)
{
    Account account;
    double balance = account.getBalance();
    ASSERT_EQ(0, balance);
}

// tests below have two first line similar -> use TestFixture to reuse
class AccountTestFixture: public testing::Test
{
 public:
    AccountTestFixture();
    virtual ~AccountTestFixture();
    void SetUp() override;
    void TearDown() override;
    static void SetUpTestCase();
    static void TearDownTestCase();
 protected:
    //Account account;    
    Account account;       // apply example TearDown
};

AccountTestFixture::AccountTestFixture()
 {
    std::cout << "Constructor called\n";
    
}

AccountTestFixture::~AccountTestFixture()
{
    std::cout << "Destructor called\n";
}   

void AccountTestFixture::SetUp()
{
    std::cout << "SetUp called\n";
    account.deposit(10.5);
}

void AccountTestFixture::TearDown()
{
    std::cout << "TearDown called\n";
}

void AccountTestFixture::SetUpTestCase()
{
    std::cout << "SetUpTestCase called\n";
}

void AccountTestFixture::TearDownTestCase()
{
    std::cout << "TearDownTestCase called\n";
}

// before without TestFixture
TEST(AccountTest, TestDeposit_No_Fixture)
{
    Account account;
    account.deposit(10.5);
    
    account.withdraw(3);

    ASSERT_EQ(7.5, account.getBalance());
}

// after with TestFixture
TEST_F(AccountTestFixture, TestDeposit_Fixture)
{  
    std::cout << "Test body\n";
    account.withdraw(3);

    ASSERT_EQ(7.5, account.getBalance());
}

TEST_F(AccountTestFixture, TestWithdrawOK)
{
    account.withdraw(3);

    ASSERT_EQ(7.5, account.getBalance());
}

TEST_F(AccountTestFixture, TestWithdrawInsufficientFunds)
{
    ASSERT_THROW(account.withdraw(300), std::runtime_error);
}

TEST_F(AccountTestFixture, TestTransferOK)
{
    Account to;
    
    account.transfer(to, 2);

    ASSERT_EQ(8.5, account.getBalance());
    ASSERT_EQ(2, to.getBalance());
}

TEST_F(AccountTestFixture, TestTransferInsufficientFunds)
{
    Account to;

    ASSERT_THROW(account.transfer(to, 200), std::runtime_error);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}