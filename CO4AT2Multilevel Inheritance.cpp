#include <iostream>
using namespace std;

class Marks
{
protected:
    int m1, m2, m3;

public:
    void accept()
    {
        cout << "Enter marks of Subject 1: ";
        cin >> m1;

        cout << "Enter marks of Subject 2: ";
        cin >> m2;

        cout << "Enter marks of Subject 3: ";
        cin >> m3;
    }
};

class Total : public Marks
{
protected:
    int total;

public:
    void calculateTotal()
    {
        total = m1 + m2 + m3;
    }
};

class Percentage : public Total
{
    float percentage;

public:
    void calculatePercentage()
    {
        percentage = total / 3.0;
    }

    void display()
    {
        cout << "\nTotal Marks = " << total << endl;
        cout << "Percentage = " << percentage << "%" << endl;
    }
};

int main()
{
    Percentage p;

    p.accept();
    p.calculateTotal();
    p.calculatePercentage();
    p.display();

    return 0;
}