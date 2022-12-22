#include <cmath>
#include <iostream>

using namespace std;

bool f(int x) {
    if (x <= 1) {
        return false;  // 0 and 1 are not considered prime
    }

    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) {
            return false;
        }
    }

    return true;
}

bool g(int x, int d) {
    if (!(d >= 0 && d <= 9)) {
        throw "`d` must follow 0 <= d <= 9";
    }

    int tempX = x;
    while (tempX > 0) {
        int digit = tempX % 10;

        if (digit == d) {
            return true;
        }

        tempX /= 10;
    }

    return false;
}

void task_1() {
    int n, d;

    cout << "Enter 'n' : " << endl;
    cin >> n;

    while (n < 100 || n > 1000) {
        cout << "Enter 'n' again. Must be 100 - 1000" << endl;
        cin >> n;
    }

    cout << "Enter 'd' : " << endl;
    cin >> d;

    while (d < 0 || d > 9) {
        cout << "Enter 'd' again. Must be 0 - 9" << endl;
        cin >> d;
    }

    int c = 0;

    for (int i = 2; i <= n; i++) {
        c += f(i) && g(i, d);
    }

    cout << "C = " << c << endl;
}
