// fibonacci
#include <cmath>
#include <iostream>

using namespace std;

string binaryEquivalent(int n) {
    if (n == 0) {
        return "";
    }

    return binaryEquivalent(n / 2) + to_string(n % 2);
}

void task4() {
    cout << binaryEquivalent(10) << endl;
}