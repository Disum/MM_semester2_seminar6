#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"
#include "solve10.h"
enum RETURN_CODES
{
	ERR_INPUT,
	ERR_MEMORY,
	ERR_READ_MATR,
};

/* a - m*n матрица */
int main(int argc, char **argv)
{
	double *a;
	int m, n;
	char *name = 0;
	clock_t t_beg;

	if( !(argc==3 || argc==4 ) || (m = atoi(argv[1]))<=0 || (n = atoi(argv[2]))<=0 )
	{
		fprintf(stderr, "Usage: %s m n [file]\n", argv[0]);
		return ERR_INPUT;
	}

	if( argc==4 )
		name = argv[3];

	if( !(a = malloc(m*n*sizeof(double))) )
	{
		fprintf(stderr, "Not enugh memory!\n");
		return ERR_MEMORY;
	}

	if( name )
	{
		int res_read;

		res_read = read_matrix(a, m, n, name);

		if( res_read!=MATR_SUCCESS )
		{
			switch( res_read )
			{
				case MATR_ERR_OPEN:
					fprintf(stderr, "Can not open %s\n", name);
					break;
				case MATR_ERR_READ:
					fprintf(stderr, "Can not read from %s\n", name);
					break;
				default:
					fprintf(stderr, "Unknown error, code: %d\n", res_read);
			}

			free(a);
			return ERR_READ_MATR;
		}
	} else
	{
		init_matrix(a, m, n);
	}

	print_matrix(a, m, n);
	t_beg = clock();
	solve10(a, m, n);
	printf("Elapsed:\t%.2lf sec\nResult:\n", (double)(clock() - t_beg)/CLOCKS_PER_SEC);
	print_matrix(a, m, n);

	free(a);
	return 0;
}
