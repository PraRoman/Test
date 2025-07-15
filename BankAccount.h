#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

class BankAccount {
private:
    double balance;
    std::string owner;

public:
    BankAccount(const std::string& ownerName, double initialBalance) : owner(ownerName), balance(initialBalance) {
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

#endif