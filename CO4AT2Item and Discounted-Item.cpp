#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Item
{
protected:
    int item_no;
    string name;
    float price;

public:
    void acceptItem()
    {
        cout << "Enter item number: ";
        cin >> item_no;

        cout << "Enter item name: ";
        cin >> name;

        cout << "Enter price: ";
        cin >> price;
    }
};

class DiscountedItem : public Item
{
    float discount_percent;
    float discount_amount;
    float final_price;

public:
    void accept()
    {
        acceptItem();

        cout << "Enter discount percentage: ";
        cin >> discount_percent;

        discount_amount = price * discount_percent / 100;
        final_price = price - discount_amount;
    }

    void display()
    {
        cout << left << setw(10) << item_no
             << setw(15) << name
             << setw(12) << price
             << setw(12) << discount_percent
             << setw(12) << final_price << endl;
    }

    float getFinalPrice()
    {
        return final_price;
    }
};

int main()
{
    int n;
    float total = 0;

    cout << "Enter number of items: ";
    cin >> n;

    DiscountedItem item[50];

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter details of Item " << i + 1 << endl;
        item[i].accept();
    }

    cout << "\n================ ITEM BILL ================\n";

    cout << left << setw(10) << "Item No"
         << setw(15) << "Name"
         << setw(12) << "Price"
         << setw(12) << "Discount"
         << setw(12) << "Final Price" << endl;

    cout << "--------------------------------------------------------\n";

    for (int i = 0; i < n; i++)
    {
        item[i].display();
        total = total + item[i].getFinalPrice();
    }

    cout << "--------------------------------------------------------\n";
    cout << "Total Amount = Rs. " << total << endl;

    return 0;
}