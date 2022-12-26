#include <cmath>
#include <iostream>

using namespace std;

bool isRecurring(int x) {
    int digit = x % 10;
    while (x > 0) {
        if (x % 10 != digit) return false;

        x /= 10;
    }

    return true;
}

void task13() {
    int n;
    cout << "N : ";
    cin >> n;

    if (n > 0) {
        for (int i = 1; i <= n; i++) {
            if (isRecurring(i)) cout << i << " ";
        }
    }
}