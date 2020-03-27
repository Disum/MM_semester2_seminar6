#include "solve07.h"

/* a - матрица m*n */
void solve07(double *a, int m, int n)
{
	int j;
	double *b, *c, *d;

	for( b = a + n, c = a, d = a + 2*n; b<(a + m*(n - 1)); b += n, c += n, d += n )
		for( j = 1; j<(n - 1); j++ )
			b[j] = (c[j] + d[j] + b[j - 1] + b[j + 1])/5;
}
