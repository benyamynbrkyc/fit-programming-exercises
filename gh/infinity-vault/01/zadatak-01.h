#include <math.h>

#include <iostream>

using namespace std;

float takeInput();
char determineFunctionType();
float calculate(float x, char funcType);

void run() {
    float x = takeInput();

    char funcType = determineFunctionType();

    float result = calculate(x, funcType);

    cout << result << endl;
}

float takeInput() {
    float x;
    cout << "Enter x : ";
    cin >> x;
    return x;
}

char determineFunctionType() {
    char funcType;

    cout << "Enter 'c' or 's' for sine or cosine ";
    cin >> funcType;

    while (funcType != 'c' && funcType != 's') {
        cout << "Invalid input" << endl;
        cout << "Enter 'c' or 's' for sine or cosine ";

        cin >> funcType;
    }

    return funcType;
}

float calculate(float x, char funcType) {
    float result = 1.0;

    // sin
    if (funcType == 's') {
        for (int i = 1; i <= x; i++) {
            result += i / (sin(x / i) + x);
        }

        return result;
    }

    // cos
    for (int i = 1; i <= x; i++) {
        result += i / (cos(x / i) + x);
    }

    return result;
}