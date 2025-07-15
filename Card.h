#ifndef CARD_H
#define CARD_H

#include <string>

using namespace std;

class Card {
private:
    short pin;
    string owner;
    string bank;
    double balance;

public:
    Card(const string& name, const string& bankName, short pincode, double amount) : owner(name), bank(bankName), pin(pincode), balance(amount) {};

    string colour;

    void changeColor(const string& newColour);

    void deposit(int addition);

    void withdraw(int reduction);

    double getBalance();

    string getOwner() const;

    string getBank() const;

    short getPin();

    string getColor() const;
};


#endif