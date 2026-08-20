#include <iostream>
#include <string>
using namespace std;

class books
{
    string author;
    string title;
    float price;
    string publisher;
    int stock;

    static int successful;
    static int unsuccessful;

    // Private member function
    void updatePrice()
    {
        char choice;

        cout << "Do you want to update the price? (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y')
        {
            cout << "Enter new price: ";
            cin >> price;
            cout << "Price updated successfully.\n";
        }
    }

public:

    // Constructor
    books(string a, string t, float p, string pub, int s)
    {
        author = a;
        title = t;
        price = p;
        publisher = pub;
        stock = s;
    }

    void searchBook(string t, string a)
    {
        if (title == t && author == a)
        {
            cout << "\nBook Available!\n";
            cout << "Title: " << title << endl;
            cout << "Author: " << author << endl;
            cout << "Price: Rs. " << price << endl;
            cout << "Publisher: " << publisher << endl;
            cout << "Stock: " << stock << endl;

            updatePrice();

            int copies;
            cout << "Enter number of copies required: ";
            cin >> copies;

            if (copies <= stock)
            {
                float total = copies * price;

                cout << "Total cost: Rs. " << total << endl;

                // Update stock
                stock = stock - copies;

                cout << "Transaction successful.\n";
                cout << "Remaining stock: " << stock << endl;

                successful++;
            }
            else
            {
                cout << "Required copies not in stock.\n";
                unsuccessful++;
            }
        }
        else
        {
            cout << "Book not available.\n";
            unsuccessful++;
        }
    }

    static void statistics()
    {
        cout << "\nSuccessful Transactions: "
             << successful << endl;

        cout << "Unsuccessful Transactions: "
             << unsuccessful << endl;
    }
};

int books::successful = 0;
int books::unsuccessful = 0;

int main()
{
    books b1("R.K. Sharma", "C++ Programming",
             500, "Tech Publications", 10);

    string title, author;

    cout << "Enter book title: ";
    getline(cin, title);

    cout << "Enter author name: ";
    getline(cin, author);

    b1.searchBook(title, author);

    books::statistics();

    return 0;
}