#include <stdio.h>

int max(int a, int b);

int main()
{
	int N, T, i, j;
	int C[1100], V[1100];
	int dp[2200];

	while(scanf("%d %d", &N, &T) != EOF)
	{
		for(i=0; i<N; i++)
			scanf("%d %d", &C[i], &V[i]);

		for(i=0; i<=T; i++)
		{
			dp[i] = 0;
			for(j=0; j<N; j++)
			{
				if(i-C[j]>=0)
					dp[i] = max(dp[i], dp[i-C[j]]+V[j]);
			}
		}

		printf("%d\n", dp[T]);
	}
}

int max(int a, int b)
{
	if(a>b) return a;
	return b;
}