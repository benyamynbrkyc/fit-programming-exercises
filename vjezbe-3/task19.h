// todo: finish this

#include <iostream>

using namespace std;

struct Date {
    int d, m, y;
};

struct Student {
    int id;

    char fullName[50];
    Date dateOfBirth;
};

void createStudent(Student* student) {
    cout << "Enter id : ";
    cin >> student->id;

    cout << "Enter fullName : ";
    cin >> student->fullName;

    Date date;
    cout << "Enter date of birth" << endl;
    cout << "Day : ";
    cin >> date.d;

    cout << "Month : ";
    cin >> date.m;
    cout << "Year: ";
    cin >> date.y;

    student->dateOfBirth = date;
}

void output(Student* student) {
    cout << "Student " << student->id << endl;
    cout << student->fullName;
    cout << student->dateOfBirth.d << "/" << student->dateOfBirth.m << "/" << student->dateOfBirth.y << endl;
    cout << endl;
}

bool dateOfBirthValid(Date* date) {
    if (date->y > 2022) {
        return false;
    }
    if (!(date->m >= 1 && date->m <= 12)) {
        return false;
    }

    if (!(date->d >= 1 && date->d <= 31)) {
        return false;
    }

    bool leapYear = (date->y % 4 == 0 && date->y % 100 != 0) || (date->y % 400 == 0);

    // non 31 months
    if (date->m == 2 && ((leapYear && date->d > 29) || (!leapYear && date->d > 28)) || date->m == 4 && date->d > 30 || date->m == 6 && date->d > 30 || date->m == 9 && date->d > 30 || date->m == 11 && date->d > 30

    ) {
        return false;
    }

    return true;
}

void checkInvalidStudentDates(Student* student) {
    if (!dateOfBirthValid(&student->dateOfBirth)) {
        cout << "Student " << student->id << " (" << student->fullName << ") has an invalid birth date : " << student->dateOfBirth.d << "/" << student->dateOfBirth.m << "/" << student->dateOfBirth.y << endl;
    }
}

Student* findFirstWithInvalidDate(Student* students, int size) {
    for (int i = 0; i < size; i++) {
        checkInvalidStudentDates(&students[i]);
        if (!dateOfBirthValid(&students[i].dateOfBirth)) {
            return &students[i];
        }
    }

    return nullptr;
}

void task19() {
    Student students[5];

    void*(createStudentPtr)(Student*);
    void*(output*)

        for (int i = 0; i < 5; i++) {
        cout << "Enter details for Student " << i + 1 << endl;
        createStudentPtr(&students[i]);
    }

    for (int i = 0; i < 5; i++) {
        output(&students[i]);
    }

    for (int i = 0; i < 5; i++) {
        checkInvalidStudentDates(&students[i]);
    }
}