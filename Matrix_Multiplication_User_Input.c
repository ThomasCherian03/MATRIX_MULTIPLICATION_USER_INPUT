#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

// Function to perform matrix-matrix multiplication
void matrix_multiplication(int *matrix1, int *matrix2, int *result, int rows1, int cols1, int rows2, int cols2) {
    #pragma omp parallel for collapse(2) // Parallelize both loops
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i * cols2 + j] = 0; // Initialize result element to 0

            for (int k = 0; k < cols1; k++) {
                result[i * cols2 + j] += matrix1[i * cols1 + k] * matrix2[k * cols2 + j];
            }
        }
    }
}

// Function to display a matrix
void display_matrix(int *matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i * cols + j]);
        }
        printf("\n");
    }
}

int main() {
    int rows1, cols1, rows2, cols2;

    // Input dimensions for the first matrix
    printf("Enter the number of rows for the first matrix: ");
    scanf("%d", &rows1);
    printf("Enter the number of columns for the first matrix: ");
    scanf("%d", &cols1);

    // Input dimensions for the second matrix
    printf("Enter the number of rows for the second matrix: ");
    scanf("%d", &rows2);
    printf("Enter the number of columns for the second matrix: ");
    scanf("%d", &cols2);

    // Ensure matrix multiplication is possible (cols1 should be equal to rows2)
    if (cols1 != rows2) {
        printf("Matrix multiplication not possible. Number of columns in the first matrix must equal the number of rows in the second matrix.\n");
        return -1;
    }

    // Dynamically allocate memory for both matrices and the result matrix
    int *matrix1 = (int *)malloc(rows1 * cols1 * sizeof(int));
    int *matrix2 = (int *)malloc(rows2 * cols2 * sizeof(int));
    int *result = (int *)malloc(rows1 * cols2 * sizeof(int));

    // Input elements of the first matrix
    printf("Enter the elements of the first matrix (row-wise):\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            printf("Matrix1[%d][%d]: ", i, j);
            scanf("%d", &matrix1[i * cols1 + j]);
        }
    }

    // Input elements of the second matrix
    printf("Enter the elements of the second matrix (row-wise):\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            printf("Matrix2[%d][%d]: ", i, j);
            scanf("%d", &matrix2[i * cols2 + j]);
        }
    }

    // Perform matrix multiplication
    matrix_multiplication(matrix1, matrix2, result, rows1, cols1, rows2, cols2);

    // Display the first matrix
    printf("\nFirst Matrix:\n");
    display_matrix(matrix1, rows1, cols1);

    // Display the second matrix
    printf("\nSecond Matrix:\n");
    display_matrix(matrix2, rows2, cols2);

    // Display the result matrix
    printf("\nResultant Matrix (Matrix1 * Matrix2):\n");
    display_matrix(result, rows1, cols2);

    // Free dynamically allocated memory
    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}
