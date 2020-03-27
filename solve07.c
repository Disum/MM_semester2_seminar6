#include "solve07.h"

/* a - матрица m*n */
void solve07(double *a, int m, int n)
{
	int j;
	double *b, *c, *d, buffer;

	for( b = a + n, c = a, d = a + 2*n; b<(a + (m - 1)*n); c = b, b = d, d += n )
	{
		buffer = b[0];
		for( j = 1; j<(n - 1); j++ )
			b[j] = buffer = (c[j] + d[j] + buffer + b[j + 1])/5;
	}
}
