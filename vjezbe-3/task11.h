#include <cmath>
#include <iostream>

using namespace std;

struct Complex {
    int real;
    int imag;
};

Complex sum(Complex a, Complex b) {
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

Complex subtract(Complex a, Complex b) {
    Complex result;
    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;
    return result;
}

Complex multiply(Complex a, Complex b) {
    Complex result;
    result.real = (a.real * b.real) - (a.imag * b.imag);
    result.imag = (a.real * b.imag) * (a.imag * b.real);
    return result;
}

Complex divide(Complex a, Complex b) {
    Complex result;
    int denominator = b.real * b.real + b.imag * b.imag;
    result.real = (a.real * b.real + a.imag * b.imag) / denominator;
    result.imag = (a.imag * b.real - a.real * b.imag) / denominator;
    return result;
}

void task11() {
    Complex a, b;

    cout << "Unesite realni dio prvog kompleksnog broja: ";
    cin >> a.real;
    cout << "Unesite imaginarni dio prvog kompleksnog broja: ";
    cin >> a.imag;

    cout << "Unesite realni dio drugog kompleksnog broja: ";
    cin >> b.real;
    cout << "Unesite imaginarni dio drugog kompleksnog broja: ";
    cin >> b.imag;

    cout << "Suma : " << sum(a, b).real << " + " << sum(a, b).imag << endl;
    cout << "Razlika : " << subtract(a, b).real << " + " << subtract(a, b).imag << endl;
    cout << "Proizvod : " << multiply(a, b).real << " + " << multiply(a, b).imag << endl;
    cout << "Kolicina : " << divide(a, b).real << " + " << divide(a, b).imag << endl;
}