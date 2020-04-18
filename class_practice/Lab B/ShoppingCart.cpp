#include "ShoppingCart.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

ShoppingCart::ShoppingCart()
{
    //ctor
    customerName = "none";
}
ShoppingCart::ShoppingCart(string name) {
    customerName = name;
}
string ShoppingCart::getCustomerName() {
    return customerName;
}
void ShoppingCart::addItem(ItemToPurchase what) {
    cartItems.push_back(what);
}
void ShoppingCart::removeItem(string yeet){
    bool temp = false;
    for(size_t i = 0; i < cartItems.size(); i++) {
        if(cartItems[i].getName() == yeet) {
            cartItems.erase(cartItems.begin() + i);
            temp = true;
        }
    }
    if(temp == false) {
        cout << "Item not found in cart. Nothing removed." << endl;
    }
}
void ShoppingCart::changeQuantity(string yeet, int n) {
    bool temp = false;
    for(size_t i = 0; i < cartItems.size(); i++) {
        if(cartItems[i].getName() == yeet) {
            cartItems[i].setQuantity(n);
            temp = true;
        }
    }
    if(temp == false) {
        cout << "Item not found in cart. Nothing modified." << endl;
    }
}
double ShoppingCart::getTotalCost() {
    double sum = 0;
    for(size_t i = 0; i < cartItems.size(); i++) {
        sum += cartItems[i].getQuantity() * cartItems[i].getPrice();
        //cout << "Index: " << i << " " << cartItems[i].getName() << endl;
    }

    return sum;
}
void ShoppingCart::printCart(){
    cout << customerName << "'s Shopping Cart" << endl;
    for(size_t i = 0; i < cartItems.size(); i++) {
        cartItems.at(i).printItemCost();
    }
    cout << "Total: $"  << getTotalCost() << endl;
}















