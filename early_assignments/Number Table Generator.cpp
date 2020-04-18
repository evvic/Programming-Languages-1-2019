// TODO (1): Includes and namespace
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ios>
#include <cmath>
using namespace std;
// TODO (2): Define useful constants (widths, file name)
const char full = '-';
// In the main() function ...
int main() {
    // TODO (3): Declare local variables
    int start = 0, stop = 0, step = 0;
    bool loop = true;
    ofstream outFS; ///output file stream

    // TODO (4): Acquire start, stop, and step values from user (validated, use a while loop while numbers are not valid)
    do {
        cout << "Enter start, stop, and step values (space separated): ";
        cin >> start >> stop >> step;

        //cout << endl << "start: " << start << " stop: " << stop << " step: " << step;
        cout << endl;

        if(stop <= start) {
            cout << "Oops! stop value must be greater than start value." << endl;
            loop = true;
            //continue;
        }
        else if(step <= 0) {
            cout << "Oops! step value must be greater than 0." << endl;
            loop = true;
            //continue;
        }
        else if((double)(stop - start)/(step) >= 50) {
            cout << "Oops! number of iterations should not exceed 50." << endl;
            loop = true;
            //continue;
        }
        else loop = false;

    } while (loop);

    // TODO (5): Open output file for write (check-for / handle error)
    outFS.open("number-table.txt");

    if(!outFS) cout << endl << "error opening number-table.txt";

    // TODO (6): Write table header to file
    outFS << setw(45) << setfill('-') << '-' << endl;
    outFS << setw(10) << setfill(' ') << "Number" << setw(10) << "Squared" <<  setw(10) <<"Cubed" << setw(15) << "Square-Root" << endl;
    outFS << setw(45) << setfill('-') << '-' << endl;
    // TODO (7): Construct `for` loop. For each iteration...
    for(start; start <= stop; start += step) {
        outFS << setw(10) << setfill(' ') << start << setw(10) << (start * start) << setw(10) << (start * start * start);
        outFS << setw(15) << fixed << setprecision(8) << (double)sqrt(start) << endl;
    }
    // TODO (8): Write a row of the table to the file

    // TODO (9): Finish off the table with a dashed line
    outFS << setw(45) << setfill('-') << '-' << endl;
    // TODO (10): Close the file and write a message to `cout`
    outFS.close();
    cout << "Table written to number-table.txt" << endl;
    // (Don't forget to return 0 at the end of the main function)
    return 0;
}
