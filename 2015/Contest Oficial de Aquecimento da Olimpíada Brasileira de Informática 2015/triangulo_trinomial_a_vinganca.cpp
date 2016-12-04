#include <stdio.h>

using namespace std;

#define MOD 2147483647

int main()
{
	long long R, D;
	scanf("%lld", &R);
	long long ans = 1; 
	long long P = 3;

	while(R) { 
	    if(R%2==1) ans = (ans*P)%MOD; 
	    P = (P*P)%MOD;
	    R = (R/2); 
	}

	printf("%lld\n", ans);

	return 0;
}