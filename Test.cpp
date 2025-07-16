#include <iostream>
#include "gtest/gtest.h"
#include <string>

#include "Card.h"
#include "BankAccount.h"

using namespace std;

//BankAccount tests

TEST(BankAccountTest, ConstructorTest) {
    BankAccount acc("Ivan", 1000);
    EXPECT_EQ(acc.getOwner(), "Ivan");
    EXPECT_DOUBLE_EQ(acc.getBalance(), 1000.0);
}

TEST(BankAccountTest, DepositTest) {
    BankAccount acc("Ivan", 1000);
    acc.deposit(500);
    EXPECT_DOUBLE_EQ(acc.getBalance(), 1500.0);
}

TEST(BankAccountTest, WithdrawTest) {
    BankAccount acc("Ivan", 1000);
    acc.withdraw(400);
    EXPECT_DOUBLE_EQ(acc.getBalance(), 600.0);
}

TEST(BankAccountTest, NegativeDepositTest) {
    BankAccount acc("Ivan", 1000);
    acc.deposit(-100);
    EXPECT_DOUBLE_EQ(acc.getBalance(), 1000.0);
}

TEST(BankAccountTest, NegativeWithdrawTest) {
    BankAccount acc("Ivan", 1000);
    acc.withdraw(-300);
    EXPECT_DOUBLE_EQ(acc.getBalance(), 1000.0);
}

TEST(BankAccountTest, NonNegativeBalanceTest) {
    BankAccount acc("Ivan", 500);
    EXPECT_TRUE(acc.hasNonNegativeBalance());

    acc.withdraw(600);
    EXPECT_FALSE(acc.hasNonNegativeBalance());
}

//Card Tests

TEST(CardTest, ConstructorSetsFieldsCorrectly) {
    Card card("Ivan", "Sberbank", 1234, 1000);

    EXPECT_EQ(card.getOwner(), "Ivan");
    EXPECT_EQ(card.getBank(), "Sberbank");
    EXPECT_EQ(card.getPin(), 1234);
    EXPECT_DOUBLE_EQ(card.getBalance(), 1000.0);
}

TEST(CardTest, DepositIncreasesBalance) {
    Card card("Ivan", "Sberbank", 1234, 500);
    card.deposit(1000);
    EXPECT_DOUBLE_EQ(card.getBalance(), 1500.0);
}

TEST(CardTest, WithdrawDecreasesBalance) {
    Card card("Ivan", "Sberbank", 1234, 1000);
    card.withdraw(300);
    EXPECT_DOUBLE_EQ(card.getBalance(), 700.0);
}

TEST(CardTest, NegativeDepositDoesNothing) {
    Card card("Ivan", "Sberbank", 1234, 1000);
    card.deposit(-100);
    EXPECT_DOUBLE_EQ(card.getBalance(), 1000.0);
}

TEST(CardTest, NegativeWithdrawDoesNothing) {
    Card card("Ivan", "Sberbank", 1234, 1000);
    card.withdraw(-200);
    EXPECT_DOUBLE_EQ(card.getBalance(), 1000.0);
}

TEST(CardTest, ChangeColorUpdatesField) {
    Card card("Ivan", "Sberbank", 1234, 1000);
    card.changeColor("red");
    EXPECT_EQ(card.getColor(), "red");
}

int main(int argc, char **argv) {
    
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}