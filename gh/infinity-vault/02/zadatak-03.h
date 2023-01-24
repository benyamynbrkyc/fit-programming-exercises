#include <iostream>

using namespace std;

int takeN();

void run() {
    int n = takeN();

    int even = 0;

    int processedN = n;
    while (processedN > 0) {
        int lastDigit = processedN % 10;

        if (lastDigit % 2 == 0) {
            even = (even * 10) + 5;
        } else {
            even = (even * 10) + lastDigit;
        }

        processedN /= 10;
    }

       // flip number to get original and done

    cout << "Original number : " << n << endl;
    cout << "Even number : " << even << endl;
    cout << "Diff " << n - even << endl;
}

int takeN() {
    int n;
    cout << "Enter n : ";
    cin >> n;
    return n;
}