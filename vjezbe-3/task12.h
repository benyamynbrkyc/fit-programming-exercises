#include <cmath>
#include <iostream>

using namespace std;

struct Student {
    int num;
    char name[50];
    char surname[50];
    int numOfAbsentHoursJustified;
    int numOfAbsentHoursUnjustified;
};

int getTotalJustified(Student students[3], int i) {
    if (i == 3) {
        return 0;
    }

    return students[i].numOfAbsentHoursJustified + getTotalJustified(students, i + 1);
}

int getTotalUnjustified(Student students[3], int len) {
    int total = 0;
    for (int i = 0; i < len; i++) {
        total += students[i].numOfAbsentHoursJustified;
    }
    return total;
}

Student getLeastUnjustified(Student students[3], int len) {
    int min = students[0].numOfAbsentHoursUnjustified;
    for (int i = 0; i < len; i++) {
        int current = students[i].numOfAbsentHoursUnjustified;
        if (current < min) min = current;
    }

    for (int i = 0; i < len; i++) {
        int current = students[i].numOfAbsentHoursUnjustified;
        if (current == min) return students[i];
    }

    throw "No such student";
}

void task12() {
    Student students[3];

    for (int i = 0; i < 3; i++) {
        students[i].num = i;
        cout << "Enter Student details" << i << endl;
        cout << "First name";
        cin >> students[i].name;
        cout << "Last name";
        cin >> students[i].surname;
        cout << "Justified hours";
        cin >> students[i].numOfAbsentHoursJustified;
        cout << "Unjustified hours";
        cin >> students[i].numOfAbsentHoursUnjustified;
    }

    int arrLen = sizeof(students) / sizeof(students[0]);

    int totalJustified = getTotalJustified(students, 0);
    int totalUnjustified = getTotalUnjustified(students, arrLen);

    cout << "totalJustified " << totalJustified << endl;
    cout << "totalUnjustified " << totalUnjustified << endl;

    Student leastUnjustified = getLeastUnjustified(students, arrLen);
    cout
        << "Least unjustified " << leastUnjustified.name << " " << leastUnjustified.surname << endl;
}