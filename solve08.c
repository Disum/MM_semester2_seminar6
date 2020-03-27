#include "solve08.h"

/* a - матрица m*n */
void solve08(double *a, int m, int n)
{
	int j;
	double *b, *c, *d;

	for( b = a + (m - 2)*n, c = a + (m - 3)*n, d = a + (m - 1)*n; b>a; b -= n, c -= n, d -= n )
		for( j = n - 2; j>0; j-- )
			b[j] = (c[j] + d[j] + b[j - 1] + b[j + 1])/5;
}
