#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    srand(time(0));
    cout << rand() % 53 + 1 << endl;
    return 0;
}