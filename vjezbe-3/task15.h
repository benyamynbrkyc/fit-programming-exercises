#include <iostream>

using namespace std;

void task15() {
    int a, b, c;
    cin >> a >> b >> c;

    int *p[5] = {
        &a, &b, &c};

    cout << endl;

    cout << *p[0] << endl;
    cout << *p[1] << endl;
    cout << *p[2] << endl;
}