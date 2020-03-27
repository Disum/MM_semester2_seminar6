#include <math.h>
#include "solve04.h"

/* a - матрица m*n */
double solve04(double *a, double *x, double *b, int m, int n)
{
	int i, j;
	double buffer, *c, max = 0;

	for( i = 0, c = a; i<m; i++, c += n )
	{
		buffer = 0;

		for( j = 0; j<n; j++ )
		{
			buffer += c[j]*x[j];
		}

		buffer = fabs(buffer + b[i]);
		if( buffer>max )
			max = buffer;
	}

	return max;
}
