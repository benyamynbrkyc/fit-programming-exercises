#include <iostream>

using namespace std;

void fillArray(int arr[99]) {
    for (int i = 0; i < 99; i++) {
        arr[i] = 300 + 1 + i;
    }
}

void fillArrayPointers(int a[33], int* b[33]) {
    for (int i = 0; i < 33; i++) {
        b[i] = &a[i * 3];
    }
}

void task16() {
    int a[99];
    fillArray(a);

    for (int i = 0; i < 99; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << endl;
    cout << endl;

    int* b[33];
    fillArrayPointers(a, b);

    for (int i = 0; i < 33; i++) {
        cout << *b[i] << " ";
    }
}