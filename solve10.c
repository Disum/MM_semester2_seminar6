#include "solve10.h"

/* a - матрица m*n */
void solve10(double *a, int m, int n)
{
	int j;
	double *b, *c, *d, buffer;

	for( b = a + (m - 2)*n, c = a + (m - 3)*n, d = a + (m - 1)*n; b>a; b -= n, c -= n, d -= n )
	{
		buffer = b[0];
		for( j = 1; j<(n - 1); j++ )
			b[j] = buffer = (c[j] + d[j] + buffer + b[j + 1])/5;
	}
}
