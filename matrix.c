#include <stdio.h>
#include "matrix.h"
#define M_MAX 10
#define N_MAX 10

/* a - матрица m*n */

int read_matrix(double *a, int m, int n, const char *name)
{
	FILE *f;
	int i, len = m*n;

	if( !(f = fopen(name, "r")) )
		return MATR_ERR_OPEN;

	for( i = 0; i<len; i++ )
		if( fscanf(f, "%lf", a + i )!=1 )
		{
			fclose(f);
			return MATR_ERR_READ;
		}

	fclose(f);
	return MATR_SUCCESS;
}

double f(int n, int i, int j)
{
	(void)n;
	(void)i;
	(void)j;

	return n - (i>j ? i : j);
}

void init_matrix(double *a, int m, int n)
{
	int i, j;
	double *b;

	for( i = 0, b = a; i<m; i++, b += n )
		for( j = 0; j<n; j++ )
			b[j] = f(n, i, j);
}

void print_matrix(double *a, int m, int n)
{
	int j, m_max, n_max;
	double *b;

	m_max = (m>M_MAX ? M_MAX : m);
	n_max = (n>N_MAX ? N_MAX : n);

	for( b = a; b<(a + m_max*n); b += n )
	{
		for( j = 0; j<n_max; j++ )
			printf("\t%lf", b[j]);
		printf("\n");
	}
}
