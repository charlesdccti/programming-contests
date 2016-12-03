#include <cstdio>

using namespace std;

typedef unsigned long long int uint64;

int main()
{
	uint64 N, L;

	while (scanf("%llu %llu", &N, &L)!=EOF) {
		printf("%llu\n", N*L);
	}

}