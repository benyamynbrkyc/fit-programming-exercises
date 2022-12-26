#include <cmath>
#include <iostream>

using namespace std;

bool isPrime(int x) {
    if (x < 2) {
        return false;
    }

    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) {
            return false;
        }
    }

    return true;
}

int reverse(int x) {
    int reversedNum = 0;

    while (x > 0) {
        reversedNum = reversedNum * 10 + x % 10;
        x /= 10;
    }

    return reversedNum;
}

void task6() {
    int n;
    cout << "N : ";
    cin >> n;

    for (int i = 2; i <= n; i++) {
        if (isPrime(i) && isPrime(reverse(i))) {
            cout << i << " ";
        }
    }
}