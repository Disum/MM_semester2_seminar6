#include "solve09.h"

/* a - матрица m*n */
void solve09(double *a, int m, int n)
{
	int j;
	double *b, *c, *d, buffer;

	for( b = a + n, c = a, d = a + 2*n; b<(a + (m - 1)*n); b += n, c += n, d += n )
	{
		buffer = b[n - 1];
		for( j = n - 2; j>0; j-- )
			b[j] = buffer = (c[j] + d[j] + b[j - 1] + buffer)/5;
	}
}
