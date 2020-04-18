#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#include "ItemToPurchase.h"

ItemToPurchase::ItemToPurchase()
{
    itemName = "nome";
    itemPrice = 0;
    itemQuantity = 0;
}

ItemToPurchase::ItemToPurchase(string name, double price, int quantity)
{
    itemName = name;
    itemPrice = price;
    itemQuantity = quantity;
}

void ItemToPurchase::setName(string n)
{
    itemName = n;
}

void ItemToPurchase::setPrice(double p)
{
    itemPrice = p;
}

void ItemToPurchase::setQuantity(int q)
{
    itemQuantity = q;
}

string ItemToPurchase::getName() const
{
    return itemName;
}

double ItemToPurchase::getPrice() const
{
    return itemPrice;
}

int ItemToPurchase::getQuantity() const
{
    return itemQuantity;
}

void ItemToPurchase::printItemCost()
{

    cout << itemName << " " << itemQuantity << " @ $" << fixed << std::setprecision(2) << itemPrice << " = $" << itemPrice * itemQuantity;
}
