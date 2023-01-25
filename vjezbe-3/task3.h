// fibonacci
#include <cmath>
#include <iostream>

using namespace std;

int calculateFibonacci(int n) {
    if (n <= 1) {
        return n;
    }

    return calculateFibonacci(n - 1) + calculateFibonacci(n - 2);
}

void task3() {
    cout << calculateFibonacci(5) << endl;  // 21
}