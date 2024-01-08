#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
/**
 * @file matrix.c
 * @brief Function definitions file for functions needed
 *          in Assignment 7.
 * @author LIYIHAI 23345919
 * @version 2.0
 * @date 2023-11-27
*/


int alloc_matrix(double ***in,  int const rows, int const cols) 
{
    /* Allocating memories for row indexes */
    double ** matrix  = malloc(rows*sizeof(double *));
    if (matrix == NULL) {
        perror("Error allocate matrix memories\n");
        exit(EXIT_FAILURE);
    }

    /* Allocating memories for each row */
    for (int row = 0; row < rows; row++){
        matrix[row] = malloc(cols*sizeof(double));
        if (matrix[row] == NULL) {
            perror("Error allocate matrix memories\n");
            exit(EXIT_FAILURE);
        }
    }
    *in = matrix;

    /* Allocating Success */
    return EXIT_SUCCESS;
}

void free_matrix(double **in, int const rows) 
{
    /* free allocate memories for each row */
    for (int r_idx = 0; r_idx < rows; r_idx ++ ){
        free(in[r_idx]);
    }
    /* free allocate memory for row address */
    free(in);
}

void print_matrix(double **A, int const m, int const n) 
{
    /* Input error checking */
    if (A == NULL) {
        printf("Error passing pointer\n");
        exit(EXIT_FAILURE);
    }

    /* Print matrix */
    for (int row = 0; row < m; row ++){
        printf("| ");
        for (int col = 0; col < n; col ++){
            if (col != 0) printf("\t");
            printf("%.2lf",A[row][col]);
        }
        printf(" \t|\n");
    }
}


void matrix_multiply(const int m, const int n, const int r, double A[m][n], double *B /*B_{n r} */, double **Res /* Res_{m r} */){
    /* Input error checking */
    if (B == NULL || Res == NULL) {
        perror("Error passing memories.\n");
        exit(EXIT_FAILURE);
    }
    
    /* Allocating B1 for accessing B (n x r) as B[i][j].*/
    double **B1 = malloc(n*sizeof(double *));
    if (B1 == NULL) {
        perror("Error allocating memory\n");
        exit(EXIT_FAILURE);
    } else {
        /* Assign address to row pointer B1 */
        for (int col = 0; col < n; col ++){
            B1[col] = &(B[col*r]);
        }
    }

    /* Allocating memories for Result matrix Res (m x r) */
    for (int row = 0; row < m; row++){
        Res[row] = malloc(r*sizeof(double));
        if (Res[row] == NULL) {
            perror("Error allocate matrix memories\n");
            exit(EXIT_FAILURE);
        }
    }
    
    /* Calculating results */
    for (int row = 0; row < m; row++ ) {
        for (int col = 0; col < r; col++ ) {
            /* Formula: Res[row][col] = < A[row][1:n], B[1:n][col] > */
            Res[row][col] = 0;
            for (int mid = 0; mid < n; mid++){
                Res[row][col] += A[row][mid] * B1[mid][col];
            }
        }
    }

}
