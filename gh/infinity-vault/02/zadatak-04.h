#include <iostream>

using namespace std;

int takeN();
void startGoldbach(int, int);
bool isPrime(int);
void goldbach(int);

void run() {
    cout << "N2 needs to be bigger than N1" << endl;
    int n1 = takeN();
    int n2 = takeN();

    startGoldbach(n1, n2);
}

void startGoldbach(int n1, int n2) {
    for (int i = n1; i <= n2; i++) {
        if (i % 2 == 0) {
            goldbach(i);
        }
    }
}

void goldbach(int num) {
    for (int i = num / 2, j = num / 2; i <= num; i++, j--) {
        if (isPrime(i) && isPrime(j)) {
            cout << i << " + " << j << " = " << num << endl;
            break;
        }
    }
}

int takeN() {
    int n;
    cout << "Enter num : ";
    cin >> n;
    return n;
}

bool isPrime(int num) {
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}
