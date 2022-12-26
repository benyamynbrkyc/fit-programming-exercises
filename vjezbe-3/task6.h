#include <cmath>
#include <iostream>

using namespace std;

void takeInput(int arr[], int i, int len) {
    if (i >= len) {
        return;
    }

    cout << "Unesi element niza :";
    cin >> arr[i];

    takeInput(arr, i + 1, len);
}

void printArray(int arr[], int i, int len) {
    if (i >= len) {
        return;
    }

    cout << arr[i] << endl;

    printArray(arr, i + 1, len);
}

int calculateSum(int arr[], int len, int i, int sum) {
    if (i >= len) {
        return sum;
    }

    sum += arr[i];

    return calculateSum(arr, len, i + 1, sum);
}

void task6() {
    int len;
    cout << "Enter length of arr : ";
    cin >> len;

    int arr[len];

    takeInput(arr, 0, len);

    printArray(arr, 0, len);

    int sum = calculateSum(arr, len, 0, 0);
    cout << "Sum of the elements added up recursively = " << sum << endl;
}
