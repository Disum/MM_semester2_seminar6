#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"
#include "solve04.h"
enum RETURN_CODES
{
	ERR_INPUT,
	ERR_MEMORY,
	ERR_READ_MATR,
};

/* a - m*n матрица */
int main(int argc, char **argv)
{
	double *a, *x, *b, res;
	int m, n, res_read;
	char *name_a = 0, *name_x = 0, *name_b = 0;
	clock_t t_beg;

	if( !(argc==3 || argc==4 || argc==5 || argc==6 ) || (m = atoi(argv[1]))<=0 || (n = atoi(argv[2]))<=0 )
	{
		fprintf(stderr, "Usage: %s m n [file_x] [file_b] [file_a]\n", argv[0]);
		return ERR_INPUT;
	}

	if( argc>3 )
	{
		name_x = argv[3];
	}
	if( argc>4 )
	{
		name_b = argv[4];
	}
	if( argc>5 )
	{
		name_a = argv[5];
	}

	if( !(a = malloc(m*n*sizeof(double))) )
	{
		fprintf(stderr, "Not enugh memory!\n");
		return ERR_MEMORY;
	}
	if( !(x = malloc(n*sizeof(double))) )
	{
		fprintf(stderr, "Not enugh memory!\n");
		free(a);
		return ERR_MEMORY;
	}
	if( !(b = malloc(m*sizeof(double))) )
	{
		fprintf(stderr, "Not enugh memory!\n");
		free(a);
		free(x);
		return ERR_MEMORY;
	}

	if( name_a )
	{
		res_read = read_matrix(a, m, n, name_a);

		if( res_read!=MATR_SUCCESS )
		{
			switch( res_read )
			{
				case MATR_ERR_OPEN:
					fprintf(stderr, "Can not open %s\n", name_a);
					break;
				case MATR_ERR_READ:
					fprintf(stderr, "Can not read from %s\n", name_a);
					break;
				default:
					fprintf(stderr, "Unknown error, code: %d\n", res_read);
			}

			free(a);
			free(x);
			free(b);
			return ERR_READ_MATR;
		}
	} else
	{
		init_matrix(a, m, n);
	}

	if( name_x )
	{
		res_read = read_matrix(x, n, 1, name_x);

		if( res_read!=MATR_SUCCESS )
		{
			switch( res_read )
			{
				case MATR_ERR_OPEN:
					fprintf(stderr, "Can not open %s\n", name_x);
					break;
				case MATR_ERR_READ:
					fprintf(stderr, "Can not read from %s\n", name_x);
					break;
				default:
					fprintf(stderr, "Unknown error, code: %d\n", res_read);
			}

			free(a);
			free(x);
			free(b);
			return ERR_READ_MATR;
		}
	} else
	{
		init_matrix(x, n, 1);
	}

	if( name_b )
	{
		res_read = read_matrix(b, m, 1, name_b);

		if( res_read!=MATR_SUCCESS )
		{
			switch( res_read )
			{
				case MATR_ERR_OPEN:
					fprintf(stderr, "Can not open %s\n", name_b);
					break;
				case MATR_ERR_READ:
					fprintf(stderr, "Can not read from %s\n", name_b);
					break;
				default:
					fprintf(stderr, "Unknown error, code: %d\n", res_read);
			}

			free(a);
			free(x);
			free(b);
			return ERR_READ_MATR;
		}
	} else
	{
		init_matrix(b, m, 1);
	}

	printf("Matrix A:\n");
	print_matrix(a, m, n);
	printf("Matrix X:\n");
	print_matrix(x, n, 1);
	printf("Matrix B:\n");
	print_matrix(b, m, 1);
	t_beg = clock();
	res = solve04(a, x, b, m, n);
	printf("Result:\t%lf\nElapsed:\t%.2lf sec\n", res, (double)(clock() - t_beg)/CLOCKS_PER_SEC);

	free(a);
	free(x);
	free(b);
	return 0;
}
