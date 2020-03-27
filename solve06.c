#include <math.h>
#include "solve06.h"

/* a - матрица m*n */
double solve06(double *a, double *b, int m, int n)
{
	int i, j, k;
	double buffer, *c, *d, sum, max = 0;

	for( j = 0, d = b; j<m; j++, d++ )
	{
		sum = 0;

		for( i = 0, c = a; i<m; i++, c += n )
		{
			if( i==j )
				buffer = -1;
			else
				buffer = 0;

			for( k = 0; k<n; k++ )
				buffer += c[k]*d[k*m];

			sum += fabs(buffer);
		}

		if( sum>max )
			max = sum;
	}

	return max;
}
