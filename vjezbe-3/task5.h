#include <cmath>
#include <iostream>

using namespace std;

double kamata(double s, double p, int g) {
    if (g == 0) {
        return s;
    }

    return kamata(s + (s * (p / 100)), p, g - 1);
}

void task5() {
    cout << kamata(1000, 5, 10) << endl;  // Ispis: 1628.89
}