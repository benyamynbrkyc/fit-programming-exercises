#include <cmath>
#include <iostream>

using namespace std;

int calculateSum(int n, int m) {
    if (n == m) {
        return pow(n, 2);
    }

    return pow(n, 2) + calculateSum(n + 1, m);
}

void task2() {
    cout << calculateSum(3, 6) << endl;
}