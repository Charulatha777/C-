#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string name;
    string address;
    long long phone_no;

public:
    void acceptPerson()
    {
        cout << "Enter name: ";
        cin >> name;

        cout << "Enter address: ";
        cin >> address;

        cout << "Enter phone number: ";
        cin >> phone_no;
    }
};

class Employee : public Person
{
    int eno;
    string ename;

public:
    void accept()
    {
        cout << "\nEnter Employee Details\n";

        cout << "Enter Employee Number: ";
        cin >> eno;

        cout << "Enter Employee Name: ";
        cin >> ename;

        acceptPerson();
    }

    void display()
    {
        cout << "\nEmployee Number: " << eno << endl;
        cout << "Employee Name: " << ename << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Phone Number: " << phone_no << endl;
    }
};

class Manager : public Person
{
    string designation;
    string department_name;
    double basic_salary;

public:
    void accept()
    {
        cout << "\nEnter Manager Details\n";

        cout << "Enter Designation: ";
        cin >> designation;

        cout << "Enter Department Name: ";
        cin >> department_name;

        cout << "Enter Basic Salary: ";
        cin >> basic_salary;

        acceptPerson();
    }

    void display()
    {
        cout << "\nDesignation: " << designation << endl;
        cout << "Department: " << department_name << endl;
        cout << "Basic Salary: " << basic_salary << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Phone Number: " << phone_no << endl;
    }

    double getSalary()
    {
        return basic_salary;
    }

    string getName()
    {
        return name;
    }
};

int main()
{
    int n;
    cout << "Enter number of employees and managers: ";
    cin >> n;

    Employee emp[50];
    Manager mgr[50];

    int choice;

    do
    {
        cout << "\n========== MENU ==========\n";
        cout << "1. Accept Details\n";
        cout << "2. Display Details\n";
        cout << "3. Highest Paid Manager\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\n--- Employee Details ---\n";
            for (int i = 0; i < n; i++)
            {
                cout << "\nEmployee " << i + 1 << endl;
                emp[i].accept();
            }

            cout << "\n--- Manager Details ---\n";
            for (int i = 0; i < n; i++)
            {
                cout << "\nManager " << i + 1 << endl;
                mgr[i].accept();
            }
            break;

        case 2:
            cout << "\n========== EMPLOYEES ==========\n";

            for (int i = 0; i < n; i++)
            {
                emp[i].display();
            }

            cout << "\n========== MANAGERS ==========\n";

            for (int i = 0; i < n; i++)
            {
                mgr[i].display();
            }
            break;

        case 3:
        {
            int highest = 0;

            for (int i = 1; i < n; i++)
            {
                if (mgr[i].getSalary() > mgr[highest].getSalary())
                {
                    highest = i;
                }
            }

            cout << "\n========== HIGHEST PAID MANAGER ==========\n";
            cout << "Name: " << mgr[highest].getName() << endl;
            cout << "Basic Salary: "
                 << mgr[highest].getSalary() << endl;

            break;
        }

        case 4:
            cout << "Program exited.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}