#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#include "ItemToPurchase.h"

int main()
{
    ItemToPurchase eric;
    ItemToPurchase aaron;

    string name;
    double price;
    int quantity;

    cout << "Enter the item name:" << endl;
    getline(cin, name);
    eric.setName(name);

    cout << "Enter the item price:" << endl;
    cin >> price;
    eric.setPrice(price);

    cout << "Enter the item quantity:" << endl;
    cin >> quantity;
    eric.setQuantity(quantity);

    cout << "Enter the item name:" << endl;
    cin.ignore();
    getline(cin, name);
    aaron.setName(name);

    cout << "Enter the item price:" << endl;
    cin >> price;
    aaron.setPrice(price);

    cout << "Enter the item quantity:" << endl;
    cin >> quantity;
    aaron.setQuantity(quantity);

    eric.printItemCost();
    aaron.printItemCost();

    cout << "Total: $" << fixed << std::setprecision(2) << (eric.getPrice() * eric.getQuantity()) + (aaron.getPrice() * aaron.getQuantity()) << endl;
}
