#include <cstdlib>
#include <iostream>

using namespace std;

void run() {
    srand(time(0));

    int rollCount = 0;
    int matchCount = 0;
    for (;;) {
        if (matchCount == 2) {
            break;
        }

        rollCount++;
        int x, y, z;
        x = rand() % 6 + 1;
        y = rand() % 6 + 1;
        z = rand() % 6 + 1;

        if (x == y && y == z && x == z) {
            cout << "Svi jednaki " << endl;
            cout << "x , y , z : " << x << y << z << endl;
            cout << "Broj bacanja " << rollCount << endl;
            matchCount++;
        } else {
            matchCount = 0;
        }
    }
}