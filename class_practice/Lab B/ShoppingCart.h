#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include "ItemToPurchase.h"
#include <vector>
#include <string>
using namespace std;

class ShoppingCart
{
    public:
        ShoppingCart();
        ShoppingCart(string name);
        string getCustomerName();
        void addItem(ItemToPurchase what);
        void removeItem(string yeet);
        void changeQuantity(string, int);
        double getTotalCost();
        void printCart();

    protected:

    private:
        string customerName;
        vector<ItemToPurchase> cartItems;
};

#endif // SHOPPINGCART_H
