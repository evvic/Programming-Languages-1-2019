/*#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
} */
#include <iostream> ///came with C++
#include "ItemToPurchase.h"///quotations tells compiler this was a user defined header file
#include <string>
#include <iomanip>


using namespace std;
//cout << fixed << setprecision(2);

int main()
{

    ItemToPurchase stuff;
    ItemToPurchase moreStuff;

    string name;
    double price;
    int quantity;

    cout << "Enter the item name: " << endl;
    //cin.ignore();
    getline(cin, name);
    //cin.ignore();
    stuff.setName(name);
    cout << "Enter the item price: " << endl;
    cin >> price;
    stuff.setPrice(price);
    cout << "Enter the item quantity: " << endl;
    cin >> quantity;
    stuff.setQuantity(quantity);

    cout << "Enter the item name: " << endl;
    cin.ignore();
    getline(cin, name);
    //cin.ignore();
    moreStuff.setName(name);
    cout << "Enter the item price: " << endl;
    cin >> price;
    moreStuff.setPrice(price);
    cout << "Enter the item quantity: " << endl;
    cin >> quantity;
    moreStuff.setQuantity(quantity);
    //stuff.itemToPurchase(name, price, quantity);

    stuff.printItemCost();
    moreStuff.printItemCost();

    cout << "Total: $" << (stuff.getPrice() * stuff.getQuantity()) + (moreStuff.getPrice() * moreStuff.getQuantity()) << endl;

    return 0;
}

