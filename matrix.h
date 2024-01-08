/**
 * @file matrix.h
 * @brief Header file containing function prototypes for functions needed for Assignment 7 of 5613.
 * @author R. Morrin
 * @version 1.0
 * @date 2023-11-23
 */
#ifndef MATRIX_H_WUM2V0LF
#define MATRIX_H_WUM2V0LF

/**
 * @brief Function to allocate memory for a matrix
 * 	This function will allocate memory for an "rows x cols" matrix.
 * 	It will first allocate memory for "rows" pointers and then 
 * 	one malloc each for "rows" rows with cols columns.
 *
 * @param[in] in 	Address of the Matrix (double ***)
 * @param[in] rows 	Number of rows to allocate
 * @param[in] cols 	Number of columns per row
 *
 * @return 0 if successful. -1 otherwise
 */
int alloc_matrix(double ***in,  int const rows, int const cols);


/**
 * @brief Function to free up memory for matrix dynamically allocated by alloc_matrix function
 *
 * @param[in] in 	Matrix to free
 * @param[in] rows 	Number of rows in Matrix
 */
void free_matrix(double **in, int const rows);


/**
 * @brief Simple function to print m x n matrix to the screen
 *
 * @param[in] A Matrix which we want to print (double **)
 * @param[in] m number of rows in the matrix
 * @param[in] n number of columns in the matrix
 */
void print_matrix(double **A, int const m, int const n);


/**
 * @brief Function to multiply two matrices.
 * 	This function is made deliberately complicated. 
 *  You would not do this in the real world.
 * 
 * 	The first matrix parameter is passed in to A[m][n].
 * 	The second is passed in as a pointer to a single contigous 
 *  block of n x r doubles. 
 * 
 *  You need to set up an array of pointers to pointers 
 *                    - double **B1 - 
 *  so that you can access the values of B as B1[i][j] etc.
 * 
 * 	The results matrix is dynamically allocated using 
 *  one malloc for an array of pointers and one malloc for 
 *  each row.
 *
 * @param[in] m 	Number of rows in Matrix A (and Matrix Res)
 * @param[in] n 	Number of columns in Matrix A, number of rows in Matrix B
 * @param[in] r 	Number of columns in Matrix B (and Matrix Res)
 * @param[in] A[m][n] 	First Matrix. Stored in a statically allocated 2d array
 * @param[in] B 	Second Matrix. Stored in a statically allocated 1d array
 * @param[out] Res 	Results Matrix. Dynamically allocated with one malloc per row
 */
void matrix_multiply(const int m, const int n, const int r, double A[m][n], double *B, double **Res);

/**
 * @brief Calculate the dot product of two vectors.
 * @note The function takes in two n-element vectors u and v as arguments.
 * It calculates their dot product and returns the answer.
 * @f[
 *   \vec{u} \cdot \vec{v} = \sum_{k=1}^{n}u_k v_k
 * @f]
 * 
 * @param[in] X[] The array containing the first vector.
 * @param[in] Y[] The array containing the second vector.
 * @param[in] n The number of elements in each vector.
 * @return The dot product 
 * @f[
 * 		\vec{u}\cdot \vec{v}
 * @f] of the two vectors.
 */
// double 	dotprod(const double X[], const double Y[], const int n);
#endif /* end of include guard: MATRIX_H_WUM2V0LF */
