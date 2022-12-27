#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

struct Unemployed {
    char firstName[30];
    char lastName[30];
    char gender[6];
    int yearOfBirth;
    double yearsOfWorkExperience;
};

Unemployed createUnemployed() {
    Unemployed unemployed;

    cout << "Enter the first name: ";
    cin >> unemployed.firstName;

    cout << "Enter the last name: ";
    cin >> unemployed.lastName;

    cout << "Enter the gender: ";
    cin >> unemployed.gender;

    cout << "Enter the year of birth: ";
    cin >> unemployed.yearOfBirth;

    cout << "Enter the years of work experience: ";
    cin >> unemployed.yearsOfWorkExperience;

    return unemployed;
}

void printUnemployed(Unemployed *unemployed) {
    cout << unemployed->firstName << endl;
    cout << unemployed->lastName << endl;
    cout << unemployed->gender << endl;
    cout << unemployed->yearOfBirth << endl;
    cout << unemployed->yearsOfWorkExperience << endl;
}

int checkYearsOFWorkExperience(Unemployed *unemployed, int size, int years) {
    int counter = 0;
    for (int i = 0; i < size; i++) {
        if (unemployed[i].yearsOfWorkExperience > years) {
            counter++;
        }
    }
    return counter;
}

Unemployed *getFemaleUnemployed(Unemployed *unemployed, int size) {
    Unemployed females[size];

    for (int i = 0; i < size; i++) {
        if (strcmp(unemployed[i].gender, "female")) {
            females[i] = unemployed[i];
        }
    }

    return females;
}

void task13() {
    Unemployed unemployed[3];

    for (int i = 0; i < 3; i++) {
        unemployed[i] = createUnemployed();
    }

    int size = sizeof(unemployed) / sizeof(unemployed[0]);

    printUnemployed(unemployed);

    cout << endl
         << "Filter by more than years of work experience : ";
    int years;
    cin >> years;
    cout << "Num of unemployed with more than " << years << " years of we : " << checkYearsOFWorkExperience(unemployed, size, years) << endl;

    Unemployed *unemployedFemales = getFemaleUnemployed(unemployed, size);
    printUnemployed(unemployedFemales);
}