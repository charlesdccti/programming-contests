#include <stdio.h>
typedef unsigned long long ull;

int main()
{
	ull Q, i;
	int voto;
	ull Y, N;

	scanf("%llu", &Q);
	Y = N = 0;
	for (i=0; i<Q; i++) {
		scanf("%d", &voto);
		if (voto)
			N++;
		else
			Y++;
	}

	if (Y<=N)
		printf("N\n");
	else
		printf("Y\n");

	return 0;
}