#include <stdio.h>

typedef unsigned long long ull;

int main()
{
	ull a, b;
	scanf("%llu %llu", &a, &b);
	
	printf("%llu\n", (a+b)*(b-a+1)/2); 

	return 0;
}