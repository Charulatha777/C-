#include <iostream>
#include <string>
using namespace std;

class Worker
{
protected:
    int code;
    string name;
    float salary;

public:
    void acceptWorker()
    {
        cout << "Enter worker code: ";
        cin >> code;

        cout << "Enter worker name: ";
        cin >> name;

        cout << "Enter salary: ";
        cin >> salary;
    }

    void displayWorker()
    {
        cout << "\nWorker Code: " << code << endl;
        cout << "Worker Name: " << name << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Officer
{
protected:
    float DA;
    float HRA;

public:
    void acceptOfficer()
    {
        cout << "Enter DA: ";
        cin >> DA;

        cout << "Enter HRA: ";
        cin >> HRA;
    }

    void displayOfficer()
    {
        cout << "DA: " << DA << endl;
        cout << "HRA: " << HRA << endl;
    }
};

class Manager : public Worker, public Officer
{
    float TA;
    float gross_sal;

public:
    void calculate()
    {
        TA = salary * 0.10;

        gross_sal = salary + DA + HRA + TA;
    }

    void accept()
    {
        acceptWorker();
        acceptOfficer();
        calculate();
    }

    void display()
    {
        displayWorker();
        displayOfficer();

        cout << "TA: " << TA << endl;
        cout << "Gross Salary: " << gross_sal << endl;
    }
};

int main()
{
    Manager m;

    m.accept();
    m.display();

    return 0;
}