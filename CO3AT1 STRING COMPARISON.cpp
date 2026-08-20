#include <iostream>
#include <cstring>
using namespace std;

class String
{
    char str[100];

public:
    String(const char s[] = "")
    {
        strcpy(str, s);
    }

    // == operator
    bool operator==(String s)
    {
        return strcmp(str, s.str) == 0;
    }

    // > operator
    bool operator>(String s)
    {
        return strcmp(str, s.str) > 0;
    }

    // < operator
    bool operator<(String s)
    {
        return strcmp(str, s.str) < 0;
    }
};

int main()
{
    String s1("Apple");
    String s2("Banana");

    if (s1 == s2)
        cout << "Both strings are equal.\n";
    else
        cout << "Strings are not equal.\n";

    if (s1 > s2)
        cout << "First string is greater.\n";
    else
        cout << "First string is not greater.\n";

    if (s1 < s2)
        cout << "First string is smaller.\n";
    else
        cout << "First string is not smaller.\n";

    return 0;
}