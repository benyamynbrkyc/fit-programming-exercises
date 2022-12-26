#include <cmath>
#include <iostream>

using namespace std;

bool isBinary(int num) {
    while (num > 0) {
        int digit = num % 10;
        if (!(digit == 0 || digit == 1)) {
            return false;
        }

        num /= 10;
    }

    return true;
}

int numOfDigits(int num) {
    return log10(num) + 1;
}

void task10() {
    int b1, b2;
    cout << "b1 : ";
    cin >> b1;

    cout << "b2 : ";
    cin >> b2;

    if (!isBinary(b1) || !isBinary(b2)) {
        throw "Both numbers must be binary";
    }

    if (numOfDigits(b1) == numOfDigits(b2)) {
        cout << "Rezultat je " << b1 && b2;
    }
}