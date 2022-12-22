#include <cmath>
#include <iostream>

using namespace std;

int f1(int x, int d) {
    int counter = 0;

    while (x > 0) {
        int digit = x % 10;

        if (digit == d) counter++;

        x /= 10;
    }

    return counter;
}

int f2(int x, int y) {
    return x == y;
}

void task4() {
    int n, c1, c2;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter c1: ";
    cin >> c1;
    cout << "Enter c2: ";
    cin >> c2;

    int c = 0;

    for (int i = 0; i <= n; i++) {
        c += f2(c2, f1(i, c1));
    }

    cout << "C = " << c << endl;
}