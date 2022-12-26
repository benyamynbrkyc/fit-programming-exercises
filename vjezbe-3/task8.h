#include <cmath>
#include <iostream>

using namespace std;

void fillMatrix(int matrix[][3], int row, int col) {
    if (row == 3) {
        return;
    }

    cout << "Enter matrix element at index (" << row << "," << col << ") : ";
    cin >> matrix[row][col];

    if (col == 2) {
        fillMatrix(matrix, row + 1, 0);
    } else {
        fillMatrix(matrix, row, col + 1);
    }
}

void printMatrix(int matrix[][3], int row, int col) {
    if (row == 3) {
        return;
    }

    cout << matrix[row][col];

    if (col == 2) {
        cout << endl;
        printMatrix(matrix, row + 1, 0);
    } else {
        printMatrix(matrix, row, col + 1);
    }
}

// entire for now
int sumMainDiagonal(int matrix[][3], int row) {
    if (row == 3) {
        return 0;
    }

    return matrix[row][row] + sumMainDiagonal(matrix, row + 1);
}

int sumSecondaryDiagonal(int matrix[][3], int row) {
    if (row == -1) {
        return 0;
    }

    return matrix[row][row] + sumSecondaryDiagonal(matrix, row - 1);
}

void findMaxElementInMatrixRow(int matrix[][3], int row, int col, int max) {
    if (row == 3) {
        return;
    }

    int current = matrix[row][col];
    if (current > max) {
        max = current;
    }

    // last col for that row
    if (col == 2) {
        cout << "The max value for row " << row << " is " << max << endl;
        findMaxElementInMatrixRow(matrix, row + 1, 0, 0);
    } else {
        findMaxElementInMatrixRow(matrix, row, col + 1, max);
    }
}

void findMaxElementInColumn(int matrix[][3], int row, int col, int max) {
    if (col == 3) {
        return;
    }

    int current = matrix[row][col];

    if (current > max) {
        max = current;
    }

    if (row == 2) {
        cout << "The max value for column " << col << " is " << max << endl;
        findMaxElementInColumn(matrix, 0, col + 1, 0);
    } else {
        findMaxElementInColumn(matrix, row + 1, col, max);
    }
}

void task8() {
    int matrix[3][3];

    int row = 0, col = 0;

    fillMatrix(matrix, row, col);
    printMatrix(matrix, row, col);
    cout << "Sum Main diagonal: " << sumMainDiagonal(matrix, row) << endl;
    cout << "Sum Secondary diagonal: " << sumSecondaryDiagonal(matrix, 2);

    cout << "Max value by row" << endl;
    findMaxElementInMatrixRow(matrix, row, col, 0);

    cout << "Max value by column" << endl;
    findMaxElementInColumn(matrix, row, col, 0);
}