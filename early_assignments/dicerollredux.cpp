#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    // TODO (1): Initialize random number generator with correct SEED
    const int SEED = 1701
    srand(SEED)
    // TODO (2): Declare variables
    int numDice, sides;
    char d;
    bool num, dee, side;
    // TODO (3): Prompt user for designation, and read input
    cout << "Choose 1, 2, or 3 dice (6-, 10-, 12-, or 20-sided)" << endl << "Enter designation (e.g. '2d6'): ";
    cin >> numDice >> d >> sides;
    // TODO (4): Validate input
    switch(numDice) {
        case 1: case 2: case 3:
            num = true
            break;
        default:
            num = false;
            break;
        }
    dee = ('d' == d);

    switch(sides) {
        case 6: case 10: case 12: case 20:
            side = true
            break;
        default:
            side = false;
            break;
    }
    // TODO (5): If NOT valid ... output error message

    // ... else ...
    // TODO (6) Generate and print the result of roll one
    // TODO (7) Generate and print the result of roll two
    // TODO (8) Generate and print the result of roll three

    return 0;
}
