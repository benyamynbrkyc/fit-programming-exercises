#include <cmath>
#include <iostream>

using namespace std;

#include <iostream>

// Function to check if number x contains digits d1 and d2
bool check_number(int x, int d1, int d2) {
    while (x > 0) {
        int digit = x % 10;
        if (digit == d1 || digit == d2) {
            return true;
        }
        x /= 10;
    }
    return false;
}

void task2() {
    int n, d1, d2;
    std::cout << "Enter n: ";
    std::cin >> n;
    std::cout << "Enter d1: ";
    std::cin >> d1;
    std::cout << "Enter d2: ";
    std::cin >> d2;

    int sum = 0;
    for (int i = 0; i <= n; ++i) {
        if (check_number(i, d1, d2)) {
            sum += i;
        }
    }

    std::cout << "Sum: " << sum << std::endl;
}