#include <string>
#include <iostream>
#include <fstream>
using namespace std;

ifstream userIN; //input file stream data type from user input
ofstream evenOUT;
ofstream oddOUT;

int main() {

    // TODO (2): declare local variables
    string input, even, odd, stemp;
    // TODO (3): acquire input filename (validated)
    cout << "Enter the name of the input file: ";
    cin >> input;
    cout << endl;
    while(".txt" != input.substr(input.size() - 4, input.size())) {
        cout << "Only filenames ending in '.txt' are accepted!" << endl;
        cout << "Enter the name of the input file: ";
        cin >> input;
        cout << endl;
    }

    // TODO (4): open input file (abort if failure)
    userIN.open(input);

    if(!userIN) {
        cout << "Failed to open file for read: " << input << endl;
        return 1;
    }

    // TODO (5): generate output file names and open output files
    stemp = input;
    even = stemp.replace(stemp.find(".txt"), stemp.find(".txt") + 4, "-even.txt");
    stemp = input;
    odd = stemp.replace(stemp.find(".txt"), stemp.find(".txt") + 4, "-odd.txt");
    //           (check there were no errors, abort if failure)

    evenOUT.open(even);
    oddOUT.open(odd);

    if(!evenOUT) {
        cout << "Failed to open file for read: " << even << endl;
        return 1;
    }
    else if(!oddOUT) {
        cout << "Failed to open file for read: " << odd << endl;
        return 1;
    }

    ///cout << endl << "even " << even << " odd " << odd;

    // TODO (6): initialize word counts
    int eCount = 0, oCount = 0;
    // TODO (7): use a `while` loop to read in / test / output each word
    while(userIN >> stemp) {
        if(userIN.eof()) break;

        if(stemp.length() % 2 == 0) {
            eCount++;
            evenOUT << stemp << endl;
        }
        else if(stemp.length() % 2 == 1) {
            oCount++;
            oddOUT << stemp << endl;
        }
    }

    cout << (eCount + oCount) <<  " words read in from " << input <<endl;
    cout << eCount << " words written to " << even << endl;
    cout << oCount << " words written to " << odd << endl;
    // TODO (8): close all files
    evenOUT.close();
    oddOUT.close();
    userIN.close();
    // TODO (9): output summary

    return 0;
}
