#include <math.h>

#include <iostream>

using namespace std;

float takeX();
int takeM();
char getFuncType();

void run() {
    float x = takeX();
    int m = takeM();
    char funcType = getFuncType();

    float result = 0;

    switch (funcType) {
        case 's':
            for (int i = 1; i <= m; i++) {
                result += i / sin(x / i) + x;
            }
            break;
        case 'c':
            for (int i = 1; i <= m; i++) {
                result += i / cos(x / i) + x;
            }
            break;
        case 'q':
            for (int i = 1; i <= m; i++) {
                result += i / sqrt(x / i) + x;
            }
            break;
        case 'p':
            for (int i = 1; i <= m; i++) {
                result += i / (pow(x / i, 2) + x);
            }
            break;

        default:
            break;
    }

    cout << result << endl;
}

float takeX() {
    float x;
    cout << "Enter x : ";
    cin >> x;
    return x;
}

int takeM() {
    int m;
    cout << "Enter m : ";
    cin >> m;
    return m;
}

char getFuncType() {
    char funcType;

    cout << "Enter function type (s, c, q, p) : ";
    cin >> funcType;

    while (funcType != 's' && funcType != 'c' && funcType != 'q' && funcType != 'p') {
        cout << "Incorrect function type. Try again." << endl;

        cin >> funcType;
    }

    return funcType;
}