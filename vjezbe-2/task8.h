#include <cmath>
#include <iostream>

using namespace std;

void transform(int a, int b) {
    int even = 0;
    int odd = 0;

    // a
    int aCopy = a;
    while (aCopy > 0) {
        int digit = aCopy % 10;
        if (digit % 2 == 0) {
            even = even * 10 + digit;
        } else {
            odd = odd * 10 + digit;
        }
        aCopy /= 10;
    }

    // b
    int bCopy = b;
    while (bCopy > 0) {
        int digit = bCopy % 10;
        if (digit % 2 == 0) {
            even = even * 10 + digit;
        } else {
            odd = odd * 10 + digit;
        }
        bCopy /= 10;
    }

    cout << "Broj sa svim parnim ciframa : " << even << endl;
    cout << "Broj sa svim neparnim ciframa : " << odd << endl;
}

void task8() {
    int a, b;
    cout << "a : ";
    cin >> a;

    cout << "b : ";
    cin >> b;

    transform(a, b);
}