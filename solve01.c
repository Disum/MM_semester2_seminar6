#include <math.h>
#include "solve01.h"

/* a - матрица m*n */
double solve01(double *a, int m, int n)
{
	int j;
	double *b, max = 0, sum;

	for( b = a; b<(a + m*n); b += n )
	{
		sum = 0;

		for( j = 0; j<n; j++ )
			sum += fabs(b[j]);

		if( sum>max )
			max = sum;
	}

	return max;
}
