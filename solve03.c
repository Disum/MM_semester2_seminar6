#include <math.h>
#include "solve03.h"

/* a - матрица m*n */
double solve03(double *a, double *x, double *b, int m, int n)
{
	int i, j;
	double buffer, *c, res = 0;

	for( i = 0, c = a; i<m; i++, c += n )
	{
		buffer = 0;

		for( j = 0; j<n; j++ )
		{
			buffer += c[j]*x[j];
		}

		res += fabs(buffer - b[i]);
	}

	return res;
}
