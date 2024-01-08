/**
 * @file assignment7c.c
 * @brief Starting code for Q4 for Assignment 7 for 5614
 * @author R. Morrin
 * @version 1.0
 * @date 2023-11-24
 */

#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include <pthread.h>


/*! @struct _matrix_multiply_params 
 *  @brief  Structure to hold the parameters needed to call matrix_multiply
 */
typedef struct _matrix_multiply_params {
	int m; 		/*!< Number of rows for A, C 				*/
	int n; 		/*!< Number of columns for A, rows for B 		*/
	int r; 		/*!< Number of columns for B, C 			*/
	double *A; 	/*!< Holds address of start of values of matrix A 	*/
	double *B; 	/*!< Holds address of start of values of matrix B 	*/
	double **C; 	/*!< C holds address of dynamically allocated matrix 	*/
} matrix_multiply_params;


/**
 * @brief Wrapper function to call the underlying matrix_multiply function.
 * 		This function can be passed into a pthread and run.
 * 		You can note the cast used. Make sure you understand what the parameters are.
 *
 * @param[in] params pointer to a matrix_multiply_params which holds all of the necessary parameters
 */
void mult_driver(matrix_multiply_params * params){
	matrix_multiply(params->n, params->m, params->r,
			(double (*)[params->n])params->A, params->B, params->C);
	// return;
}

int main(void)
{
	double X[][3] = {{1.0, 2.0, 3.0},
		{4.0, 5.0, 6.0},
		{7.0, 8.0, 9.0}};
	double Y1[] = {1.2, 2.3, 3.4, 4.5, 5.6, 6.7};
	double Y2[] = {1.1, 2.2, 3.3};

	double **Z1  = NULL;
	if(alloc_matrix(&Z1, 3, 2) !=0){
		fprintf(stderr, "Error calling alloc_matrix");
		exit(EXIT_FAILURE);
	}

	double **Z2  = NULL;
	if(alloc_matrix(&Z2, 3, 1) !=0){
		fprintf(stderr, "Error calling alloc_matrix");
		exit(EXIT_FAILURE);
	}

	/*
	 * Create and initilize structures to hold parameters.
	 */
	matrix_multiply_params t1params = {3, 3, 2, &(X[0][0]), Y1, Z1};
	matrix_multiply_params t2params = {3, 3, 1, &(X[0][0]), Y2, Z2};


	// TODO: Spawn a new thread to call mult_driver to do one of the multiplications
	//  	 and do the other one in this thread. You can call mult_driver in this
	//  	 thread too rather than calling matrix_multiply directly.
	//  	 The two multiplication will be:
	//  	 1) Z1 = X x Y1 
	//  	 2) Z2 = X x Y2

	pthread_t t1, t2;
	int err = 0;

	err = pthread_create(&t1,
		       	NULL,  /* create with default attributes */
			(void *) mult_driver,
			(matrix_multiply_params *) &t1params);
	if(err){
		fprintf(stderr, "Error creating. return value %d\n", err);
		return EXIT_FAILURE;
	}

	err = pthread_create(&t2,
		       	NULL,  /* create with default attributes */
			(void *) mult_driver,
			(matrix_multiply_params *) &t2params);
	if(err){
		fprintf(stderr, "Error creating. return value %d\n", err);
		return EXIT_FAILURE;
	}


	if((err = pthread_join(t1, NULL) !=0)){
		fprintf(stderr, "Error joining. return value %d\n", err);
		return EXIT_FAILURE;
	}
	if((err =pthread_join(t2, NULL) !=0)){
		fprintf(stderr, "Error joining. return value %d\n", err);
		return EXIT_FAILURE;
	}

	print_matrix(Z2, 3,1);
	print_matrix(Z1, 3,2);

	free_matrix(Z1,3);
	free_matrix(Z2,3);


	
	return EXIT_SUCCESS;
}
