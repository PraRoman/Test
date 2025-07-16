#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>

using namespace std;

class BankAccount {
private:
    double balance;
    string owner;

public:
    BankAccount(const string& ownerName, double initialBalance);

    void deposit(int addition);

    void withdraw(int reduction);

    double getBalance();

    string getOwner() const;

    bool hasNonNegativeBalance();
};

#endif