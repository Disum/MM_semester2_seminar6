#include <math.h>
#include "solve02.h"

/* a - матрица m*n */
double solve02(double *a, int m, int n)
{
	int i, j;
	double *b, max = 0, sum;

	for( j = 0, b = a; j<n; j++, b++ )
	{
		sum = 0;

		for( i = 0; i<m; i++ )
			sum += fabs(b[i*n]);

		if( sum>max )
			max = sum;
	}

	return max;
}
