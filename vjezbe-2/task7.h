#include <cmath>
#include <iostream>

using namespace std;

int reverse(int x) {
    int reversedNum = 0;

    while (x > 0) {
        reversedNum = reversedNum * 10 + x % 10;

        x /= 10;
    }

    return reversedNum;
}

bool s(int x, int y) {
    int sum = 0;

    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }

    return sum == y;
}

void task7() {
    int n;
    cout << "N : ";
    cout << "N must be 0 <= n <= 1000. Pretend there's a check here :)" << endl;
    cin >> n;

    int b;
    cout << "B : ";
    cout << "B must be 0 <= b. Pretend there's a check here :)" << endl;
    cin >> b;

    for (int i = 0; i <= n; i++) {
        // is palindrome
        if (i == reverse(i) && s(i, b)) {
            cout << i << " ";
        }
    }
}