#include <cmath>
#include <iostream>

using namespace std;

struct Student {
    int num;
    string firstName;
    string lastName;
    double avgGrade;
};

void input(Student* student) {
    cout << "Enter num ";
    cin >> student->num;
    cout << "Enter firstName ";
    cin >> student->firstName;
    cout << "Enter lastName ";
    cin >> student->lastName;
    cout << "Enter avgGrade ";
    cin >> student->avgGrade;
}

void output(Student* student) {
    cout << student->num;
    cout << student->firstName;
    cout << student->lastName;
    cout << student->avgGrade;
}

Student worst(Student* s1, Student* s2, Student* s3) {
    int min = s1->avgGrade;
    Student s;

    if (s2->avgGrade < min) {
        min = s2->avgGrade;
        s.num = s2->num;
        s.firstName = s2->firstName;
        s.lastName = s2->lastName;
        s.avgGrade = s2->avgGrade;
        return s;
    }

    if (s3->avgGrade < min) {
        min = s3->avgGrade;
        s.num = s3->num;
        s.firstName = s3->firstName;
        s.lastName = s3->lastName;
        s.avgGrade = s3->avgGrade;
        return s;
    }

    s.num = s1->num;
    s.firstName = s1->firstName;
    s.lastName = s1->lastName;
    s.avgGrade = s1->avgGrade;
    return s;
}

void task14() {
    Student s1;
    input(&s1);
    output(&s1);
    Student s2;
    input(&s2);
    output(&s2);
    Student s3;
    input(&s3);
    output(&s3);

    Student worstStudent = worst(&s1, &s2, &s3);
    cout << "The worst student is ";
    output(&worstStudent);
}
