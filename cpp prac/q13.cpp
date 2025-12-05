#include <iostream>
using namespace std;

class BankAccount {
    string depositorName;
    int accountNumber;
    string accountType;
    float balance;

public:
    BankAccount(string name, int accNo, string type, float initialBalance) {
        depositorName = name;
        accountNumber = accNo;
        accountType = type;
        balance = initialBalance;
    }

    void deposit(float amount) {
        balance += amount;
    }

    void withdraw(float amount) {
        if (balance >= amount)
            balance -= amount;
        else
            cout << "Insufficient balance\n";
    }

    void display() {
        cout << "Name: " << depositorName << ", Balance: " << balance << endl;
    }
};

int main() {
    BankAccount b("Rangu", 24, "Saving", 85000);
    b.deposit(1800);
    b.withdraw(1700);
    b.display();

    return 0;
}
