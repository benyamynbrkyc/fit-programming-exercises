#include <iostream>

using namespace std;

int getNumOfDigits();

void run() {
    int numOfDigits = getNumOfDigits();

    int number = 0;

    for (int i = 0; i < numOfDigits; i++) {
        cout << "Digit no. " << i + 1 << endl;
        cout << "Enter digit : ";
        int digit;
        cin >> digit;

        if (digit < 0) {
            break;
        }

        if (digit > 9) {
            cout << "Digit is not valid." << endl;
            continue;
        }

        number = number * 10 + digit;
    }

    cout << number << endl;
}

int getNumOfDigits() {
    cout << "Enter num of digits : ";
    int num;
    cin >> num;
    return num;
}