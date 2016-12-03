#include <cstdio>
#include <string>

using namespace std;

typedef unsigned long long int uint64;

int main()
{
	uint64 N, L;
	string dec;
	while (scanf("%llu", &N)!=EOF) {
		dec.clear();
		while (N!=0) {
			if (N%16>=10) dec+=('A'+(N%16)-10);
			else dec+='0'+(N%16);
			N/=16;
		}

		for (int i = dec.size()-1; i>=0; i--) {
			printf("%c", dec[i]);
		} printf("\n");
	}

}