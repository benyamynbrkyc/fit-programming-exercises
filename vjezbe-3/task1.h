#include <cmath>
#include <iostream>

using namespace std;

int calculateSum(int n) {
    if (n == 1) {
        return 1;
    }

    return pow(n, 2) + calculateSum(n - 1);
}

void task1() {
    cout << calculateSum(4);
}