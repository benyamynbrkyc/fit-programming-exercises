#include <cmath>
#include <iostream>

using namespace std;

bool isSorted(int num) {
    int prev = num % 10;
    num /= 10;
    while (num > 0) {
        int current = num % 10;
        if (prev < current) {
            return false;
        }
        num /= 10;
    }

    return true;
}

void task15() {
    int n;
    cout << "N :  ";
    cin >> n;

    bool sorted = isSorted(n);
    if (!sorted) {
        cout << "Cifre unesenog broja nisu sortirane" << endl;
    } else {
        cout << "Cifre unesenog broja su sortirane" << endl;
    }
}