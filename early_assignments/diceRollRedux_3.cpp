#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    srand(32767);

    cout << "Enter dice throw designators..." << endl
         << " # dice: 1 to 8, # sides: 4, 6, 8, 10, 12" << endl
         << " e.g. '2d6', or '0' to quit" << endl;

    int nDice, nSides, temp, total = 0;
    char ch;
    bool will = true, inner;

    // A "forever" loop...
    while (will) {
        do {
            cout << "> ";
            cin >> nDice;
            if (nDice == 0) {
                // User signal to end the prgram
                will = false;
                break;
            }
            cin >> ch >> nSides;
            cout << endl;
            if(!(nDice < 9 && nDice >= 1 && ch == 'd' && (nSides == 4 || nSides == 6 || nSides == 8 || nSides == 10 || nSides == 12))) {
                inner = true;
                cout << "Invalid Designator" << endl;
            }
            else {
                inner = false;
            }
        } while(inner);

        // TODO (2): Start the output (e.g. "2d6 result: ")


        if(nDice != 0){
            cout << nDice << ch << nSides << " result: ";
            total = 0;
            for(int i = 1; i <= nDice; i++){
                temp = (rand() % nSides + 1);
                total = total + temp;
                cout << temp;
                if(i < nDice) {
                    cout << " + ";
                }
            }
            cout << " = " << total << endl;
        }
        // TODO (3): Throw some dice and sum/display the result
    }

    return 0;
}
