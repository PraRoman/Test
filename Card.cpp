#include "Card.h"

void Card::changeColor(const string& newColour) {
    colour = newColour;
}

void Card::deposit(int addition) {
    if (addition > 0) balance += addition;
}

void Card::withdraw(int reduction) {
    if (reduction > 0) balance -= reduction;
}

double Card::getBalance() {
    return balance;
}

string Card::getOwner() const {
    return owner;
}

string Card::getBank() const {
    return bank;
}

short Card::getPin() {
    return pin;
}

string Card::getColor() const {
    return colour;
}