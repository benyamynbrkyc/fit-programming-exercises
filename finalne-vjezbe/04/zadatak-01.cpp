#include <string.h>

#include <iostream>

using namespace std;

struct fudbaler {
    int* godRodjenja;
    int* brojIgraca;
    int* golovi;

    fudbaler() {
        godRodjenja = new int;
        brojIgraca = new int;
        golovi = new int;
    }

    ~fudbaler() {
        delete godRodjenja;
        godRodjenja = nullptr;

        delete brojIgraca;
        brojIgraca = nullptr;

        delete golovi;
        golovi = nullptr;
    }
};

void fillArr(fudbaler** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        cout << "\n"
             << "Team " << i + 1 << "\n-----------" << endl;
        for (int j = 0; j < cols; j++) {
            /*
              godRodjenja: 1980 + rand() % ((2000 + 1) - 1980) // Generiše brojeve
              u rangu 1980 - 2000

              brojIgraca: rand() % 30 + 1

              golovi: rand() % 5
            */
            cout << "\nPlayer " << j + 1 << "\n"
                 << endl;

            *(*(arr + i) + j)->godRodjenja = 1980 + rand() % ((2000 + 1) - 1980);
            cout << "God Rodjenja: " << *(*(arr + i) + j)->godRodjenja << endl;

            *(*(arr + i) + j)->brojIgraca = rand() % 30 + 1;
            cout << "Broj igraca: " << *(*(arr + i) + j)->brojIgraca << endl;

            *(*(arr + i) + j)->golovi = rand() % 5;
            cout << "Golovi: " << *(*(arr + i) + j)->golovi << endl;
        }

        cout << "-----------" << endl;
    }
}

void findTeamWithHighestAverageGoals(fudbaler** arr, int rows, int cols) {
    float highestAvgGoals = 0;
    int teamWithHighestAmountOfAvgGoals;

    for (int i = 0; i < rows; i++) {
        int rowGoals = 0;
        for (int j = 0; j < cols; j++) {
            rowGoals += *(*(arr + i) + j)->golovi;
        }

        float avgRowGoals = (float)rowGoals / (float)cols;

        if (avgRowGoals > highestAvgGoals) {
            highestAvgGoals = avgRowGoals;

            teamWithHighestAmountOfAvgGoals = i;
        }
    }

    cout << "Team with highest amount of average goals: Team "
         << teamWithHighestAmountOfAvgGoals + 1 << endl;
    cout << "Highest average goals: " << highestAvgGoals << endl;
}

int readInt() {
    int n;
    cin >> n;
    return n;
};

int main() {
    srand(time(0));
    cout << "Rows: ";
    int rows = readInt();

    cout << "Cols: ";
    int cols = readInt();

    fudbaler** arr = new fudbaler*[rows];

    for (int i = 0; i < rows; i++) {
        *(arr + i) = new fudbaler[cols];
    }

    fillArr(arr, rows, cols);

    findTeamWithHighestAverageGoals(arr, rows, cols);

    return 0;
}