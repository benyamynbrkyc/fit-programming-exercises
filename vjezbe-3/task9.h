#include <cmath>
#include <iostream>

using namespace std;

void fillMatrix(int matrix[][4], int row, int col) {
    if (row == 4) {
        return;
    }

    cout << "Enter matrix element at (" << row << "," << col << ") : ";
    cin >> matrix[row][col];

    if (col == 3) {
        fillMatrix(matrix, row + 1, 0);
    } else {
        fillMatrix(matrix, row, col + 1);
    }
}

void printMatrix(int matrix[][4], int row, int col) {
    if (row == 4) {
        return;
    }
    cout << matrix[row][col];

    if (col == 3) {
        cout << endl;
        printMatrix(matrix, row + 1, 0);
    } else {
        printMatrix(matrix, row, col + 1);
    }
}

int sumRow(int matrix[][4], int row, int col) {
    if (col == 4) {
        return 0;
    }

    return matrix[row][col] + sumRow(matrix, row, col + 1);
}

int sumCol(int matrix[][4], int row, int col) {
    if (row == 4) {
        return 0;
    }

    return matrix[row][col] + sumCol(matrix, row + 1, col);
}

int sumMainDiagonal(int matrix[][4], int row) {
    if (row == 4) {
        return 0;
    }

    return matrix[row][row] + sumMainDiagonal(matrix, row + 1);
}

int sumSecondaryDiagonal(int matrix[][4], int row) {
    if (row == -1) {
        return 0;
    }

    return matrix[row][row] + sumSecondaryDiagonal(matrix, row - 1);
}

bool isMagicSquare(int matrix[][4]) {
    bool rowsSumIsMagic = sumRow(matrix, 0, 0) == sumRow(matrix, 1, 0) == sumRow(matrix, 2, 0) == sumRow(matrix, 3, 0);
    bool colsSumIsMagic = sumCol(matrix, 0, 0) == sumCol(matrix, 0, 1) == sumCol(matrix, 0, 2) == sumCol(matrix, 0, 3);
    bool mainDiagonalSumIsMagic = sumMainDiagonal(matrix, 0);
    bool secondaryDiagonalSumIsMagic = sumSecondaryDiagonal(matrix, 3);

    return rowsSumIsMagic == colsSumIsMagic == mainDiagonalSumIsMagic == secondaryDiagonalSumIsMagic;
}

void task9() {
    int matrix[4][4];
    int row = 0, col = 0;
    fillMatrix(matrix, row, col);
    printMatrix(matrix, row, col);
    cout << "Is the matrix a magic square? " << isMagicSquare(matrix);
}