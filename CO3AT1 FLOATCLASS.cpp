#include <iostream>
using namespace std;

class FLOAT
{
    float value;

public:
    FLOAT(float v = 0)
    {
        value = v;
    }

    // Addition
    FLOAT operator+(FLOAT f)
    {
        return FLOAT(value + f.value);
    }

    // Subtraction
    FLOAT operator-(FLOAT f)
    {
        return FLOAT(value - f.value);
    }

    // Multiplication
    FLOAT operator*(FLOAT f)
    {
        return FLOAT(value * f.value);
    }

    // Division
    FLOAT operator/(FLOAT f)
    {
        return FLOAT(value / f.value);
    }

    void display()
    {
        cout << value << endl;
    }
};

int main()
{
    FLOAT f1(10.5);
    FLOAT f2(2.5);

    FLOAT sum = f1 + f2;
    FLOAT difference = f1 - f2;
    FLOAT product = f1 * f2;
    FLOAT division = f1 / f2;

    cout << "Addition: ";
    sum.display();

    cout << "Subtraction: ";
    difference.display();

    cout << "Multiplication: ";
    product.display();

    cout << "Division: ";
    division.display();

    return 0;
}