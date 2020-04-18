// TODO (1): include directives, namespace and main() function
#include <iostream>
#include <string>
using namespace std;

int main() {

    string word1, word2;
    int num1, num2;

    cout << endl << "== Fizz Buzz Deluxe ==" << endl;
// TODO (3): input (and validate) a pair of words
    do {
        cout << endl << "Enter a pair of words (each from 3-6 chars long): ";
        cin >> word1 >> word2; ///this works
    } while (!(word1.size() <=6 && word1.size() > 2 && word2.size() > 2 && word2.size() <= 6));

// TODO (4): input (and validate) a pair of divisors
    do {
        cout << endl << "Enter two different integers (between 2 and 15): ";
        cin >> num1 >> num2;
    } while(!(num1 > 2 && num1 < 15 && num2 > 2 && num2 < 15 && num1 != num2));
    cout << endl;
// TODO (5): Output "fizz buzz" sequence from 1 to 100
    for(int i = 0; i <= 90; i += 10){
        for(int j = 1; j <= 10; j++){
//            select((i*j)) {
//                case }
            if((i + j) % num1 == 0) {
                if((i + j) % num2 == 0) {
                    cout << ' ' << word1 << word2;
                    continue;
                }
                else {
                    cout << ' ' << word1;
                    continue;
                }
            }
            else if ((i + j) % num2 == 0) {
                cout << ' ' << word2;
                continue;
            }
            else {
                cout << ' ' << i + j;
                continue;
            }
            //cout << i * j << "  ";
        }
        cout << endl;
    }
    cout << endl;
// TODO (6): Output "fizz buzz" symbol map
    for(int i = 0; i <= 90; i += 10){
        for(int j = 1; j <= 10; j++){
//            select((i*j)) {
//                case }
            if((i + j) % num1 == 0) {
                if((i + j) % num2 == 0) {
                    cout << ' ' << '#';
                    continue;
                }
                else {
                    cout << ' ' << '+';
                    continue;
                }
            }
            else if ((i + j) % num2 == 0) {
                cout << ' ' << '*';
                continue;
            }
            else {
                cout << ' ' << '.';
                continue;
            }
            //cout << i * j << "  ";
        }
        cout << endl;
    }
// TODO (7): Don't forget to `return 0;` at the end of `main()`
    return 0;
}
