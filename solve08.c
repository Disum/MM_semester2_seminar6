#include "solve08.h"

/* a - матрица m*n */
void solve08(double *a, int m, int n)
{
	int j;
	double *b, *c, *d, buffer;

	for( b = a + (m - 2)*n, c = a + (m - 3)*n, d = a + (m - 1)*n; b>a; b -= n, c -= n, d -= n )
	{
		buffer = b[n - 1];
		for( j = n - 2; j>0; j-- )
			b[j] = buffer = (c[j] + d[j] + b[j - 1] + buffer)/5;
	}
}
