#include <math.h>
#include "solve11.h"

/* a - матрица m*n */
void solve11(double *a, int m, int n)
{
	int i, i_max = 0, j_max = 0;
	double *b, buffer, max = 0;

	for( i = 0; i<m*n; i++ )
	{
		buffer = fabs(a[i]);
		if( buffer>max )
		{
			i_max = i;
			max = buffer;
		}
	}

	j_max = i_max%n;
	i_max /= n;

	for( b = a; b<(a + n); b++ )
	{
		buffer = b[i_max*n];
		b[i_max*n] = b[0];
		b[0] = buffer;
	}

	for( b = a; b<(a + m*n); b += n )
	{
		buffer = b[j_max];
		b[j_max] = b[0];
		b[0] = buffer;
	}
}
