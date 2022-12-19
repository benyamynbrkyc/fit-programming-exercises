#pragma once
#include <iostream>

using namespace std;

void task_17() {
    int n;
    cout << "Enter a number between 10 and 99: ";
    cin >> n;

    while (!(n >= 10 && n <= 99)) {
        cout << "Invalid input. Try again: ";
        cin >> n;
    }

    for (int i = 10; i <= n; i++) {
        int firstDigit = i / 10;
        int secondDigit = i % 10;
        if (firstDigit + secondDigit < firstDigit * secondDigit)
            cout << i << endl;
    }
}

void task_18() {
    cout << "Enter number n > 10: ";
    int n;
    cin >> n;

    while (n <= 10) {
        cout << "Invalid input. Try again: ";
        cin >> n;
    }

    for (int i = 10; i <= n; i++) {
        if (i % 3 == 0 && i % 100 == 33) {
            cout << i << " ";
        }
    }
}

void task_19() {
    int day, month, year;
    cout << "Enter date : ";
    cin >> day >> month >> year;

    // check if date and month are valid
    if (day < 1 || day > 31 || month < 1 || month > 12) {
        cout << "Date not valid" << endl;
        return;
    }

    // check if year is leap year
    bool leap_year = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);

    if (
        (month == 2 && day > 29) || (month == 2 && day == 29 && !leap_year) ||
        (month == 4 && day > 30) || (month == 6 && day > 30) || (month == 8 && day > 30) || (month == 9 && day > 30) || (month == 11 && day > 30)) {
        cout << "Date not valid" << endl;
        return;
    }

    cout << "Date valid" << endl;
}

void task_20() {
    // Input first date
    int day1, month1, year1;
    std::cout << "Enter the day of the first date: ";
    std::cin >> day1;
    std::cout << "Enter the month of the first date: ";
    std::cin >> month1;
    std::cout << "Enter the year of the first date: ";
    std::cin >> year1;

    // Input second date
    int day2, month2, year2;
    std::cout << "Enter the day of the second date: ";
    std::cin >> day2;
    std::cout << "Enter the month of the second date: ";
    std::cin >> month2;
    std::cout << "Enter the year of the second date: ";
    std::cin >> year2;

    // Input third date
    int day3, month3, year3;
    std::cout << "Enter the day of the third date: ";
    std::cin >> day3;
    std::cout << "Enter the month of the third date: ";
    std::cin >> month3;
    std::cout << "Enter the year of the third date: ";
    std::cin >> year3;

    // Output oldest date
    if (year1 < year2 && year1 < year3) {
        std::cout << "The oldest date is: " << day1 << "." << month1 << "." << year1 << std::endl;
    } else if (year2 < year1 && year2 < year3) {
        std::cout << "The oldest date is: " << day2 << "." << month2 << "." << year2 << std::endl;
    } else {
        std::cout << "The oldest date is: " << day3 << "." << month3 << "." << year3 << std::endl;
    }
}