#include <cstdio>

int main()
{
	long long int N, S;
	scanf("%lld", &N);
	while (N--)
	{
		scanf("%lld", &S);
		if(S<=2014) printf("%lld D.C.\n", 2015-S);
		else printf("%lld A.C.\n", S-2014);
	}

	return 0;
}