#include <cmath>
#include <iostream>

using namespace std;

int max(int x, int y) {
    return x > y ? x : y;
}

int min(int x, int y) {
    return x < y ? x : y;
}

void task5() {
    int n;
    cout << "Enter n : ";
    cin >> n;

    int sum = 0;

    for (int i = -5; i <= 5; i++) {
        for (int j = 1; j <= n; j++) {
            sum += min(5, max(0, i * j));
        }
    }

    cout << "P = " << sum << endl;
}