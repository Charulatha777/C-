#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
    string name;
    long accountNo;
    string type;
    double balance;

public:
    // Constructor
    BankAccount(string n, long acc, string t, double b)
    {
        name = n;
        accountNo = acc;
        type = t;
        balance = b;
    }

    // Deposit amount
    void deposit(long acc, string n, double amount)
    {
        if (acc == accountNo && n == name)
        {
            balance = balance + amount;
            cout << "Amount deposited successfully.\n";
        }
        else
        {
            cout << "Account number or name is incorrect.\n";
        }
    }

    // Withdraw amount
    void withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance = balance - amount;
            cout << "Amount withdrawn successfully.\n";
        }
        else
        {
            cout << "Insufficient balance.\n";
        }
    }

    // Display details
    void display()
    {
        cout << "\nName: " << name << endl;
        cout << "Balance: Rs. " << balance << endl;
    }

    // Destructor
    ~BankAccount()
    {
        cout << "Bank Account object destroyed.\n";
    }
};

int main()
{
    BankAccount b("Charulatha", 123456, "Savings", 10000);

    b.display();

    b.deposit(123456, "Charulatha", 5000);
    b.display();

    b.withdraw(3000);
    b.display();

    return 0;
}