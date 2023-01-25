#include <iostream>

using namespace std;

void fibonacci();
bool isPrime(int);

void run() {
    fibonacci();
}

void fibonacci() {
    long long int next;
    int n = 2;
    long long int first = 0, second = 1;
    long long int arr[n];

    for (int i = 0; i < n; i++) {
        if (i <= 1) {
            next = i;
        } else {
            next = first + second;
            first = second;
            second = next;
        }

        arr[i] = next;
    }

    long long int sumFactorial = 0;

    for (int i = 0; i < n; i++) {
        if (isPrime(arr[i])) {
            long long int factorial = 1;
            for (int j = 1; j <= arr[i]; j++) {
                factorial *= j;
            }
            sumFactorial += factorial;
        }
    }

    cout << "Suma faktorijela prvih 100 elemenata fibonaccijevog niza = " << sumFactorial << endl;
}

bool isPrime(int num) {
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}