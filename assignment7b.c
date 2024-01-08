/**
 * @file assignment7b.c
 * @brief Starting code for Q3 of assignment 7 for 5613
 * @author R. Morrin
 * @version 1.0
 * @date 2023-11-24
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "matrix.h"

int main(void)
{

	pid_t fpid;

	if (( fpid = fork()) < 0){ /* fail to fork */
		perror("Uable to fork\n");
		exit(EXIT_FAILURE);

	} else if (fpid == 0) { /* Child process */
		
		double X[][3] = {{1.0, 2.0, 3.0},
		{4.0, 5.0, 6.0},
		{7.0, 8.0, 9.0}};
		double Y1[] = {1.2, 2.3, 3.4, 4.5, 5.6, 6.7};

		double **Z1  = NULL;
		if(alloc_matrix(&Z1, 3, 2) !=0){
			fprintf(stderr, "Error calling alloc_matrix");
			_exit(EXIT_FAILURE); /* Calling _exit for exit child process exclusively */
		}
		
		matrix_multiply(3, 3, 2, X, Y1, Z1);
		print_matrix(Z1, 3, 2);
	} else { /* else Parent process */
		
		wait(NULL);/* Wait Child process executed.*/

		double X[][3] = {{1.0, 2.0, 3.0},
		{4.0, 5.0, 6.0},
		{7.0, 8.0, 9.0}};
		double Y2[] = {1.1, 2.2, 3.3};
        
		double **Z2  = NULL;
		if(alloc_matrix(&Z2, 3, 1) !=0){
			fprintf(stderr, "Error calling alloc_matrix");
			exit(EXIT_FAILURE);
		}

		matrix_multiply(3, 3, 1, X, Y2, Z2);
		print_matrix(Z2, 3, 1);

	}
	return EXIT_SUCCESS;
}
