#include <stdio.h>
typedef unsigned long long ull;
// 1, 3, 9, 27, 81

ull pow(ull, int);

int main()
{
	ull R;
	scanf("%llu", &R);
	printf("%llu\n", pow(3,R));

	return 0;
}

ull pow(ull B, int E){
	int aux = B;

	if(E==0)
		return 1;
	while(E!=1){
		B*=aux;
		E--;
	}
	return B;
}