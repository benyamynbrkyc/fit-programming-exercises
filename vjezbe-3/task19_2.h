#include <cstring>
#include <iostream>

struct date {
    int d, m, y;
};

struct student {
    int ID;
    char Name[30];
    date birth;
};

// Function to input student characteristics
void inputStudent(student* s) {
    std::cout << "Enter student ID: ";
    std::cin >> s->ID;
    std::cout << "Enter student name: ";
    std::cin.ignore();  // Ignore the newline character left in the buffer by previous input
    std::cin.getline(s->Name, 30);
    std::cout << "Enter student birth date (dd mm yyyy): ";
    std::cin >> s->birth.d >> s->birth.m >> s->birth.y;
}

// Function to print student characteristics
void printStudent(student* s) {
    std::cout << "Student ID: " << s->ID << std::endl;
    std::cout << "Student name: " << s->Name << std::endl;
    std::cout << "Student birth date: " << s->birth.d << "-" << s->birth.m << "-" << s->birth.y << std::endl;
}

// Function to check if a date is valid
bool isValidDate(date* d) {
    // Check if the month is within the range 1-12
    if (d->m < 1 || d->m > 12) {
        return false;
    }

    // Check if the day is within the range 1-31
    if (d->d < 1 || d->d > 31) {
        return false;
    }

    // Check if the year is within a reasonable range
    if (d->y < 1900 || d->y > 2100) {
        return false;
    }

    // Check if the day is within the range for the specific month
    if ((d->m == 4 || d->m == 6 || d->m == 9 || d->m == 11) && d->d > 30) {
        return false;
    }

    // Check if it is a leap year and the month is February
    if (d->m == 2) {
        if ((d->y % 4 == 0 && d->y % 100 != 0) || d->y % 400 == 0) {
            // Leap year, check if day is within range 1-29
            if (d->d > 29) {
                return false;
            }
        } else {
            // Non-leap year, check if day is within range 1-28
            if (d->d > 28) {
                return false;
            }
        }
    }

    // If all checks pass, the date is valid
    return true;
}

// Function to count students with invalid date of birth
int countInvalidDates(student* students, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (!isValidDate(&students[i].birth)) {
            count++;
        }
    }
    return count;
}

// Function to find the first student with invalid date of birth
student* findFirstInvalidDate(student* students, int size) {
    for (int i = 0; i < size; i++) {
        if (!isValidDate(&students[i].birth)) {
            return &students[i];
        }
    }
    // If no invalid dates are found, return null
    return nullptr;
}

// Function to return the address of the last element in an array
float* last(float* arr, int size) {
    return &arr[size - 1];
}

// Function to return the address of an element chosen by the user
float* desired(float* arr, int size) {
    int index;
    std::cout << "Enter the index of the desired element: ";
    std::cin >> index;
    if (index >= 0 && index < size) {
        return &arr[index];
    } else {
        std::cout << "Invalid index" << std::endl;
        return nullptr;
    }
}

// Function to return the address of the element in an array that is closest in value to a given value
float* closest(float* arr, int size, float value) {
    float closest = arr[0];
    float* closest_ptr = &arr[0];
    for (int i = 1; i < size; i++) {
        if (abs(arr[i] - value) < abs(closest - value)) {
            closest = arr[i];
            closest_ptr = &arr[i];
        }
    }
    return closest_ptr;
}

void task19_2() {
    // Create an array of 5 students
    student students[5];

    // Input the student characteristics
    for (int i = 0; i < 5; i++) {
        std::cout << "Enter characteristics for student " << i + 1 << ":" << std::endl;
        inputStudent(&students[i]);
    }

    // Print the student characteristics
    for (int i = 0; i < 5; i++) {
        std::cout << "Characteristics for student " << i + 1 << ":" << std::endl;
        printStudent(&students[i]);
    }

    // Count and print the number of students with invalid dates of birth
    int count = countInvalidDates(students, 5);
    std::cout << "Number of students with invalid dates of birth: " << count << std::endl;

    // Find and print the first student with invalid date of birth
    student* invalid_student = findFirstInvalidDate(students, 5);
    if (invalid_student) {
        std::cout << "First student with invalid date of birth: " << std::endl;
        printStudent(invalid_student);
    } else {
        std::cout << "No students with invalid date of birth found" << std::endl;
    }

    // Create an array of floating point numbers
    float arr[5] = {1.1, 2.2, 3.3, 4.4, 5.5};

    // Get the address of the last element in the array and print it
    float* last_ptr = last(arr, 5);
    std::cout << "Address of last element: " << last_ptr << std::endl;

    // Get the address of an element chosen by the user and print it
    float* desired_ptr = desired(arr, 5);
    if (desired_ptr) {
        std::cout << "Address of desired element: " << desired_ptr << std::endl;
    }

    // Get the address of the element in the array that is closest in value to a given value and print it
    float value;
    std::cout << "Enter a value to find the closest element to: ";
    std::cin >> value;
    float* closest_ptr = closest(arr, 5, value);
    std::cout << "Address of element closest to " << value << ": " << closest_ptr << std::endl;
}