#include <iostream>

using namespace std;

/*

Svaki paran broj se može prikazati kao suma dva prosta broja (tkz. Goldbachovo pravilo). Napisati program koji će najprije učitati dva prirodna broja n1 i n2 (n2 > n1).

Zatim prikazati sve parne brojeve u intervalu od n1 do n2 kao sumu dva prosta broja.

(U glavnom programu samo unijeti navedena dva prirodna broja i pozvati funkciju koja obavlja zadani posao.)


*/

int readInt() {
    int n;
    cin >> n;
    return n;
}

bool isPrime(int num) {
    if (num <= 1) return false;

    for (int i = 2; i < num; i++)
        if (num % i == 0) return false;

    return true;
}

void gb(int n) {
    for (int i = n / 2, j = n / 2; i <= n; i++, j--)
        if (isPrime(i) && isPrime(j))
            cout << i << " + " << j << " = " << i + j << endl;
}

int main() {
    int n1 = 0, n2 = 0;
    for (;;) {
        cout << "Enter n1: ";
        n1 = readInt();

        cout << "Enter n2: ";
        n2 = readInt();

        if (n2 > n1 && n1 % 2 == 0 && n2 % 2 == 0) break;
    }

    for (int i = n1; i <= n2; i += 2)
        gb(i);

    return 0;
}
