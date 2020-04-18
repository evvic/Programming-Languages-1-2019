
// TODO (1): #include directives and namespace statement here
#include <iostream>
#include <string>
using namespace std;

int main() {
    const string LINE = "--------------------";

    // TODO (2): declare variables here

    string suitName, rankName, matchword;
    bool noMatches = true;

    // TODO (3): prompt user for matchword; read in the value
    cout << "Enter match word (\'.\' for match all): ";
    cin >> matchword;

    // TODO (4): consider declaring and initializing additional variables
    string ranks[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    string suits[4] = {"Clubs", "Hearts", "Spades", "Diamonds"};
    // TODO (5): start output with a line
    cout << endl << LINE << endl;

    // TODO (6): outer loop ..... ///[0...3] 0 => suitName = "Clubs", 1=> suitName = "Hearts", ...
    for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 13; j++) {
                if(matchword == suits[i] || matchword == ranks[j] || matchword == ".") {
                    cout << ranks[j] << " of " << suits[i] << endl;
                    noMatches = false;
                }
//                else {
//                    if(repeat) {
//                        repeat = false;
//                        cout << "(no matches)" << endl;
//                    }
//                    break;
//                }
            }
        }
    if(noMatches) {
        cout << "(no matches)" << endl;
    }
    cout  << LINE << endl;


            // TODO (8): should we print the card name?  (Does the match word equal the suit name OR the rank name?)


    // TODO: (9) output (no matches) if nothing matched


    // TODO: (10) finish output with a line

    return 0;
}
