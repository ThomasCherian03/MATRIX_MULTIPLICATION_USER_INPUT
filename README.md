# Matrix Multiplication with OpenMP

This project demonstrates matrix-matrix multiplication using OpenMP for parallel processing. The program allows the user to input the dimensions and elements of two matrices, performs the multiplication, and displays the result.

## Features

- User input for matrix dimensions and elements
- Parallelized matrix-matrix multiplication using OpenMP
- Display of matrices before and after multiplication

## Requirements

- A C compiler (e.g., GCC)
- OpenMP library (usually included with GCC)

## Compilation

To compile the program, use the following command:

```sh
gcc -o matrix_multiplication matrix_multiplication.c -fopenmp
