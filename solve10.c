#include "solve10.h"

/* a - матрица m*n */
void solve10(double *a, int m, int n)
{
	int j;
	double *b, *c, *d;

	for( b = a + m*(n - 2), c = a + m*(n - 3), d = a + m*(n - 1); b>(a + n); b -= n, c -= n, d -= n )
		for( j = 1; j<(n - 1); j++ )
			b[j] = (c[j] + d[j] + b[j - 1] + b[j + 1])/5;
}
