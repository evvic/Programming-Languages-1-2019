#ifndef ITEMTOPURCHASE_H_INCLUDED
#define ITEMTOPURCHASE_H_INCLUDED



#endif // ITEMTOPURCHASE_H_INCLUDED

class ItemToPurchase
{
public:
    ItemToPurchase();
    ItemToPurchase(string name, double price, int quantity);
    void setName(string n);
    void setPrice(double p);
    void setQuantity(int q);
    string getName() const;
    double getPrice() const;
    int getQuantity() const;
    void printItemCost();
private:
    string itemName;
    double itemPrice;
    int itemQuantity;

};
