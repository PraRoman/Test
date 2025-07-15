#include <iostream>
#include "gtest/gtest.h"
#include <string>

using namespace std;

class BankAccount {
private:
    double balance;
    std::string owner;

public:
    BankAccount(const std::string& ownerName, double initialBalance)
        : owner(ownerName), balance(initialBalance) {
    }

    void deposit(int addition) {
        if (addition > 0) balance += addition;
    }

    void withdraw(int reduction) {
        if (reduction > 0) balance -= reduction;  
    }

    double getBalance() const {
        return balance;
    }

    string getOwner() const {
        return owner;
    }

    bool hasNonNegativeBalance() const {
        return balance >= 0;
    }
};

TEST(BankAccountTest, DepAndWithdrTest) {
    BankAccount acc("Tom", 100);

    int dep = 15, red = 30;

    acc.deposit(dep);

    EXPECT_EQ(acc.getBalance(), 115);

    acc.withdraw(red);

    EXPECT_EQ(acc.getBalance(), 85);
}

int main(int argc, char **argv) {
    
  
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}