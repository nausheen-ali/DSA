#include <stdio.h>

// Function to read a matrix
void readMatrix(int rows, int cols, int matrix[rows][cols]) {
    printf("Enter the elements of the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display a matrix
void displayMatrix(int rows, int cols, int matrix[rows][cols]) {
    printf("Matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to multiply two matrices
void multiplyMatrices(int r1, int c1, int matrix1[r1][c1], int r2, int c2, int matrix2[r2][c2], int result[r1][c2]) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    int r1, c1, r2, c2;

    // Read dimensions of the first matrix
    printf("Enter the number of rows and columns for the first matrix: ");
    scanf("%d %d", &r1, &c1);

    // Read dimensions of the second matrix
    printf("Enter the number of rows and columns for the second matrix: ");
    scanf("%d %d", &r2, &c2);

    // Check for compatibility
    if (c1 != r2) {
        printf("Matrices cannot be multiplied. Number of columns in the first matrix must be equal to the number of rows in the second matrix.\n");
        return 1;
    }

    int matrix1[r1][c1], matrix2[r2][c2], result[r1][c2];

    // Read the matrices
    readMatrix(r1, c1, matrix1);
    readMatrix(r2, c2, matrix2);

    // Display the matrices
    printf("First ");
    displayMatrix(r1, c1, matrix1);
    printf("Second ");
    displayMatrix(r2, c2, matrix2);

    // Multiply the matrices
    multiplyMatrices(r1, c1, matrix1, r2, c2, matrix2, result);

    // Display the result
    printf("Product of the matrices:\n");
    displayMatrix(r1, c2, result);

    return 0;
}
