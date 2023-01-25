#include <iostream>

using namespace std;

int takeN();
bool isPrime(int);
float calculatePercentage(float, float);

void run() {
    srand(time(0));
    int n = takeN();

    float numOfPrimes = 0;

    for (int i = 0; i < n; i++) {
        int newNum = rand() % 1000 + 1;
        if (isPrime(newNum)) {
            numOfPrimes++;
        }
    }

    int percentage = calculatePercentage(numOfPrimes, n);

    cout << "Percentage of primes - " << percentage << "%" << endl;
    cout << "Num of primes - " << percentage << " | "
         << "Total nums : " << n << endl;
}

float calculatePercentage(float numOfPrimes, float n) {
    return (numOfPrimes / n) * 100.00;
}

bool isPrime(int num) {
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

int takeN() {
    int n;
    cout << "Enter n : ";
    cin >> n;

    while (!(n >= 10 && n <= 1000)) {
        cout << "N needs to be between 10 and 1000. Enter n : " << endl;
        cin >> n;
    }

    return n;
}