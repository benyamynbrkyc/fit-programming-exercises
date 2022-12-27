#include <cmath>
#include <iostream>

using namespace std;

void input(float* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter array element : ";
        cin >> arr[i];
    }
}

float* last(float* arr, int size) {
    return &arr[size - 1];
}

float* wanted(float* arr, int size) {
    int idx;
    cout << "Enter the index of the element you wish to fetch : ";
    cin >> idx;

    if (idx >= size) {
        throw "Invalid index";
    }

    return &arr[idx];
}

float* closestValue(float* arr, int size) {
    float value;
    cout << "Get element closest in value to : ";
    cin >> value;

    float* closest = &arr[0];
    float diff = fabs(arr[0] - value);

    for (int i = 0; i < size; i++) {
        float currentDiff = fabs(arr[i] - value);
        if (currentDiff < diff) {
            closest = &arr[i];
            diff = currentDiff;
        }
    }

    return closest;
}

void output(float* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void assign(float* (*arrPointers[3])(float*, int)) {
    arrPointers[0] = last;
    arrPointers[1] = wanted;
    arrPointers[2] = closestValue;
}
<
    void task18() {
    int size = 5;
    float arr[size];

    input(arr, size);
    output(arr, size);

    float* (*arrPointers[3])(float*, int);
    assign(arrPointers);

    for (int i = 0; i 3; i++) {
        cout << *arrPointers[0](arr, size) << endl;
        cout << *arrPointers[1](arr, size) << endl;
        cout << *arrPointers[2](arr, size) << endl;
    }
}