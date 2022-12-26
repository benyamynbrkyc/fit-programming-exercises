#include <cmath>
#include <iostream>

using namespace std;

void fillMatrix(int matrix[][3], int row, int column) {
    if (column == 3) {
        column = 0;
        row = row + 1;
    }

    if (row == 3) {
        return;
    }

    int element;
    cout << "Enter element for position (" << row << "," << column << "): ";
    cin >> element;

    matrix[row][column] = element;

    fillMatrix(matrix, row, column + 1);
}

void printMatrix(int matrix[][3], int row, int column) {
    if (column == 3) {
        column = 0;
        row++;
    }

    if (row == 3) {
        return;
    }

    cout << matrix[row][column];
    column++;
    if (column == 3) cout << endl;

    printMatrix(matrix, row, column);
}

int sumMatrixElements(int matrix[][3], int row, int col) {
    if (col == 3) {
        return sumMatrixElements(matrix, ++row, 0);
    }

    if (row == 3) {
        return 0;
    }

    return matrix[row][col] + sumMatrixElements(matrix, row, col + 1);
}

int sum_matrix(int matrix[][3], int row, int col) {
    // Base case: if we have reached the last column, add the element and move to the next row
    if (col == 3) {
        return matrix[row][col - 1] + sum_matrix(matrix, row + 1, 0);
    }
    // Base case: if we have reached the last row, return 0
    if (row == 3) {
        return 0;
    }
    // Recursive case: add the element and move to the next column

    return matrix[row][col] + sum_matrix(matrix, row, col + 1);
}

void task7() {
    int matrix[3][3];

    fillMatrix(matrix, 0, 0);

    printMatrix(matrix, 0, 0);

    cout << "Sum of matrix elements = " << sumMatrixElements(matrix, 0, 0) << endl;
    // cout << "Sum of matrix elements = " << sum_matrix(matrix, 0, 0) << endl;
}