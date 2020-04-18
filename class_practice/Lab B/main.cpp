
#include <iostream> ///came with C++
#include "ItemToPurchase.h"///quotations tells compiler this was a user defined header file
#include "ShoppingCart.h"
#include <string>
#include <iomanip>


using namespace std;
///cout << fixed << setprecision(2);

int main()
{

    ItemToPurchase stuff;

    string name;
    double price;
    int quantity;

    cout << "Name: " << endl;
    getline(cin, name);
    ShoppingCart cart(name);

    for(int v = 0; v < 3; v++) {
        cout << "Enter the item name: " << endl;

        getline(cin, name);
        stuff.setName(name);
        cout << "Enter the item price: " << endl;
        cin >> price;
        stuff.setPrice(price);
        cout << "Enter the item quantity: " << endl;
        cin >> quantity;
        cin.ignore();
        stuff.setQuantity(quantity);
        cart.addItem(stuff);
        cout << endl;
    }


    cart.printCart();

    return 0;
}

