/**
 * @file assignment7a.c
 * @brief Use this as the main function for Q2 for Assignment 7 for 5613
 *  		You will need to write the function definitions for 
 *  			1) alloc_matrix
 *  			2) free_matrix
 *  			3) print_matrix
 *  			4) matrix_multiply
 * 		Write these in matrix.c
 *
 * @author R. Morrin
 * @version 1.0
 * @date 2023-11-23
 */

#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"


int main(void)
{
	double X[][3] = {{1.0, 2.0, 3.0},
		{4.0, 5.0, 6.0},
		{7.0, 8.0, 9.0}};

	double Y1[] = {1.2, 2.3, 3.4, 4.5, 5.6, 6.7};

	double **Z1  = NULL;

	if(alloc_matrix(&Z1, 3, 2) !=0){
		fprintf(stderr, "Error calling alloc_matrix");
		exit(EXIT_FAILURE);
	}

	alloc_matrix(&Z1, 3, 2);

	matrix_multiply(3, 3, 2, X, Y1, Z1);

	print_matrix(Z1, 3, 2);
	free_matrix(Z1, 3);

	return 0;
}
