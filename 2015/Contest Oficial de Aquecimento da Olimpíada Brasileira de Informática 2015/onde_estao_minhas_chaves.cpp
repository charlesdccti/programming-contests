#include <stdio.h>

int main()
{
	int Q, E, i, j;
	scanf("%d %d", &Q, &E);
	int X[E];

	for(i=0; i<E; i++)
		scanf("%d", &X[i]);

	int Y[Q];
	int v;
	for(i=0; i<Q; i++){
		scanf("%d", &Y[i]);
		v = 0;
		for(j=0; j<E; j++){
			if(Y[i] == X[j])
				v = 1;
		}
		for(j=0; j<i; j++){
			if(Y[i] == Y[j])
				v = 1;
		}
		if(v)
			printf("0\n");
		else
			printf("1\n");
	}

	return 0;
}