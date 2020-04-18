
            /* FIX LINE 12 & 27 & 28,
            HOW TO CONVERT INT TO STRING*/
#include <iostream>
#include <ios>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

ofstream outFS; ///output file stream
///string name = "times-table-0.txt";

int main() {

    int table = 0;
    string name = "times-table-0.txt";

    do {
        cout << "Enter the table size (from 1 to 12): ";
        cin >> table;
        cout << endl;
    } while (table <= 0 || table > 12);
  // TODO (5): Generate the filename
    ///string temp = table.str();
    ///name.replace(13, 1 , temp);
  // TODO (6): Open output file for write (abort, if an error occurs)
    outFS.open("times-table-0.txt");
    if(!outFS) return 0;

  // TODO (7): Write table column headers
    outFS << setw(4) << setfill('-') << '+' << setw(4*table) << setfill('-') << '-' << endl;
    outFS << " x |";
    for(int e = 1; e <= table; e++) {
        outFS << setw(4) << setfill(' ') << e;
    }
    outFS << endl << setw(4) << setfill('-') << '+' << setw(4*table) << setfill('-') << '-' << endl;

    for(int i = 1; i <= table; i++) {
        outFS << setw(2) << setfill(' ') << i << " |";
        for(int j = 1; j <= table; j++) {
            outFS << setw(4) << setfill(' ') << i * j;
        }
        outFS << endl;
    }

    outFS << setw(4) << setfill('-') << '+' << setw(4*table) << setfill('-') << '-' << endl;

    cout << "Output written to " << name << '!' << endl;
    outFS.close();
    return 0;
}
