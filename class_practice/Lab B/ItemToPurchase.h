/*#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H


class ItemToPurchase
{
    public:
        ItemToPurchase();

    protected:

    private:
};

#endif // ITEMTOPURCHASE_H */

#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H

#include <string>
using namespace std;

///header file has to carry the prototypes: aka the declarations
class ItemToPurchase
{
    public:
        ItemToPurchase();
        ItemToPurchase(string name, double price, int quantity);
        void setName(string s);
        void setPrice(double p);
        void setQuantity(int q);
        string getName();
        double getPrice();
        int getQuantity();
        void printItemCost();


    protected:

    private:
        string itemName;
        double itemPrice;
        int itemQuantity;
};

#endif // ITEMTOPURCHASE_H
