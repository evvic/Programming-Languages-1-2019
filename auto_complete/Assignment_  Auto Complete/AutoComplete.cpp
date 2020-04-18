#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int MAX_SIZE = 4000000;
const string FILE_NAME = "GoogleWords.txt";
string a[MAX_SIZE];

void insertionSort(string a[], int siz);
int binarySearch(string a[], string key, int size);
int readDictionary(string a[], string fileName);
void writeDictionary(string a[], int size, string fileName);
int updateDictionary(string a[], int size, string s, string fileName);
void outputMatches(string a[], int size, string s);

int main()
{
    int size = readDictionary(a, FILE_NAME);
    //cout << "   Must've read dictionary in" << endl;
    string input;
    cout << "Type one word.  \"q\" to quit." << endl;
    cout << "> ";
    cin >> input;
    while(input != "q")
    {
        outputMatches(a, size, input);
        //cout << "   main size: " << size << endl;
        size = updateDictionary(a, size, input, FILE_NAME);
        cout << "> ";
        cin >> input;
    }
    return 0;
}

///TODO(0)  define binarySearch
int binarySearch(string a[], string key, int size) {
    int mid, low, high;
    //cout << "      binary search" << endl;

    low = 0;
    high = size - 1;

    while(high > low) {
        mid = (high + low) / 2;
        if(a[mid] < key) {
            low = mid + 1;
            //cout << "low: " << low << endl;
        }
        else if(a[mid] > key) {
            high = mid - 1;
            //cout << "high: " << high << endl;
        }
        else return mid;
    }


    return -1; //if couldn't find
}
///TODO(1)  define insertionSort
void insertionSort(string a[], int siz){
    int i, j;
    string temp;
    //cout << "      insertion sort" << endl;

    for(i = 1; i < siz; i++) {
        j = i;

        while(j > 0 && a[j] < a[j - 1]) {
            temp = a[j];
            a[j] = a[j - 1];
            a[j - 1] = temp;
            --j;
        }
    }
}

///TODO(2)  define readDictionary
int readDictionary(string a[], string fileName){
    string burn;
    int i = 0;
    ifstream ifName(fileName);

    if(ifName) {
        //cout << "   File opened successfully (readDictionary)" << endl; //checking
        while(ifName >> a[i]) { // >> burn
            i++;
            if(a[i] == " " || a[i] == "\n") cout << "array is blank" << endl;
            a[i] = burn;
            //cout << "  array: " << a[i] << "  burn: " << burn; //checking extraction
        }
    }
    //cout << endl;
    ifName.close();
    return i;
}

/*
- Open an ifstream using fileName
- Read one word at a time, separated by \n, into a
- return the number of words read.  This will be used for size throughout the rest of the code.
*/

///TODO(3)  define writeDictionary
void writeDictionary(string a[], int size, string fileName) {
    ofstream ofName(fileName);
    if(ofName) {
        //cout << "   ofName successfully opened, size: " << size << endl;
        for(int i = 0; i < size; i++) {
            //cout << i << " " << a[i] << endl;
            ofName << a[i] << "\n";
        }
    }
    ofName.close();
}
/*
- Open an ofstream using fileName
    - Use its default behavior of deleting the existing file, we will write a new one.
- Write each element of a to the file.
*/

///TODO(4)  define updateDictionary
int updateDictionary(string a[], int size, string s, string fileName){
    int position = binarySearch(a, s, size);
    //cout << "   Update Dictionary..." <<endl;
    if(position == -1) {
        a[size] = s;
        size++;
        insertionSort(a, size);
    }

    writeDictionary(a, size, fileName);

    return size;
}

/*
- Use binarySearch to search a for s.
- If s is NOT found at a valid index:
    - assign s to the end of the array.
        - The index of the end of the array is size.  eg if size is 5, the new element should be written to index 5.
    - increment size
    - Sort a using insertionSort
    - Write a to the file using writeDictionary
*/

///TODO(5)  define outputMatches
void outputMatches(string a[], int size, string s) {
    for(int i = 0; i < size; i++) {
        if(a[i].find(s) == 0) {

            cout << a[i] << endl;
        }
    }
}
/*
- loop through each element of a
    - call .find on each element, searching for s
    - If the element begins with s, ie the index returned from .find is 0, then print the element
*/
