#include <cmath>
#include <iostream>

using namespace std;

struct circle {
    float x;
    float y;
    float radius;
};

void checkRadius(circle *c, int desiredQuadrant) {
    if (c->radius > abs(c->x) || c->radius > abs(c->y)) {
        throw "The radius cannot be larger than either x or y because the circle has to fall in quadrant " + desiredQuadrant;
    }
}
void task10() {
    circle c1 = {4, 4};

    int r1;
    cout << "Enter radius of c1 : ";
    cin >> r1;
    c1.radius = r1;

    checkRadius(&c1);
    checkRadius(&c2);
    checkRadius(&c3);
    checkRadius(&c);

    // mrsko mi ovo majke mi
}