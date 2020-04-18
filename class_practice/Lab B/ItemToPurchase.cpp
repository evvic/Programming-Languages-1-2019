/*#include "ItemToPurchase.h"

ItemToPurchase::ItemToPurchase()
{
    //ctor
} */
#include "ItemToPurchase.h" ///means we want to include everything declared in the header file here
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

///implement the methods and variable created in its header file
ItemToPurchase::ItemToPurchase() ///constructor
{
    //ctor
    itemName = "none";
    itemPrice = 0;
    itemQuantity = 0;
}
ItemToPurchase::ItemToPurchase(string name, double price, int quantity) ///constructor2
{
    //ctor
    itemName = name;
    itemPrice = price;
    itemQuantity = quantity;
}
void ItemToPurchase::setName(string s) {
    itemName = s;
}
void ItemToPurchase::setPrice(double p) {
    itemPrice = p;
}
void ItemToPurchase::setQuantity(int q) {
    itemQuantity = q;
}

string ItemToPurchase::getName() {
    return itemName;
}
double ItemToPurchase::getPrice(){
    return itemPrice;
}
int ItemToPurchase::getQuantity(){
    return itemQuantity;
}
void ItemToPurchase::printItemCost() {
        cout << itemName << " " << itemQuantity << " @ $" << fixed << std::setprecision(2) << itemPrice << " = $" << itemPrice * itemQuantity << endl;
}
