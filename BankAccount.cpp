#include "BankAccount.h"

BankAccount::BankAccount(const string& ownerName, double initialBalance) : owner(ownerName), balance(initialBalance) {}

void BankAccount::deposit(int addition) {
	if (addition > 0) balance += addition;
}

void BankAccount::withdraw(int reduction) {
	if (reduction > 0) balance -= reduction;
}

double BankAccount::getBalance() {
	return balance;
}

string BankAccount::getOwner() const {
	return owner;
}

bool BankAccount::hasNonNegativeBalance() {
	return balance >= 0;
}