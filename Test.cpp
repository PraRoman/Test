#include <iostream>
#include "gtest/gtest.h"
#include <string>

using namespace std;

TEST(SampleTests, Test1) {
    EXPECT_EQ(1, 1);
}

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

    std::string getOwner() const {
        return owner;
    }

    bool hasNonNegativeBalance() const {
        return balance >= 0;
    }
};

int main(int argc, char **argv) {
    
    BankAccount person("Tom", 35000);
    person.getInfo();
    person.withdraw(10000);
    person.deposit(150000);
    person.getInfo();
    
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}