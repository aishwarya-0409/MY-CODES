
#include <iostream>
using namespace std;

class Account {
protected:
    string customerName;
    int accNumber;
    string accType;
    float balance;

public:
    void initialize(string name, int number, string type, float bal) {
        customerName = name;
        accNumber = number;
        accType = type;
        balance = bal;
    }

    void deposit(float amount) {
        balance += amount;
    }

    void displayBalance() {
        cout << "Customer: " << customerName << ", Balance: " << balance << endl;
    }
};

class CurrAcct : public Account {
public:
    void withdraw(float amount) {
        if (balance - amount < 500) {
            cout << "Penalty imposed! Minimum balance required.\n";
            balance -= 50; // Penalty
        }
        balance -= amount;
    }
};

class SavAcct : public Account {
public:
    void computeInterest() {
        float interest = balance * 0.04;
        balance += interest;
    }

    void withdraw(float amount) {
        if (balance >= amount)
            balance -= amount;
        else
            cout << "Insufficient funds\n";
    }
};

int main() {
    CurrAcct current;
    SavAcct saving;

    current.initialize("sharvi", 1001, "Current", 1000);
    saving.initialize("ria", 1002, "Saving", 2000);

    current.deposit(500);
    current.withdraw(1100);
    current.displayBalance();

    saving.deposit(1000);
    saving.computeInterest();
    saving.withdraw(2500);
    saving.displayBalance();

    return 0;
}
