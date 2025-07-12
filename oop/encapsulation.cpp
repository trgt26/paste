#include <iostream>
using namespace std;

class BankAccount {
private:
    string accountHolder;
    double balance;

public:
    BankAccount(string name, double initialBalance) {
        accountHolder = name;
        balance = initialBalance;
    }

    // Public method to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited $" << amount << " successfully." << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    // Public method to withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew $" << amount << " successfully." << endl;
        } else {
            cout << "Invalid or insufficient amount." << endl;
        }
    }

    // Public method to check balance
    void displayBalance() {
        cout << "Account Holder: " << accountHolder << ", Balance: $" << balance << endl;
    }
};

int main() {
    BankAccount account("Alice", 1000.0);
    account.deposit(500);
    account.withdraw(200);
    account.displayBalance();

    // account.balance = 10000; // ❌ Not allowed (private)
    // account.accountHolder = "Bob"; // ❌ Not allowed (private)

    return 0;
}
