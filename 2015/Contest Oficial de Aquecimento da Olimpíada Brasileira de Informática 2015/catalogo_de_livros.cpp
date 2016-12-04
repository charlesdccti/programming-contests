#include <iostream>
#include <stdio.h>

void trocaValores(int* a, int* b);
int divide(int vec[], int esquerdo, int direito);
void quickSort(int vec[], int esquerdo, int direito);

int main()
{
	int P, M, F, Q, B, i;

	scanf("%d", &P);
	int arP[P];
	for(i=0; i<P; i++)
		scanf("%d", &arP[i]);

	scanf("%d", &M);
	int arM[M];
	for(i=0; i<M; i++)
		scanf("%d", &arM[i]);

	scanf("%d", &F);
	int arF[F];
	for(i=0; i<F; i++)
		scanf("%d", &arF[i]);

	scanf("%d", &Q);
	int arQ[Q];
	for(i=0; i<Q; i++)
		scanf("%d", &arQ[i]);

	scanf("%d", &B);
	int arB[B];
	for(i=0; i<B; i++)
		scanf("%d", &arB[i]);


	int total[P*M*F*Q*B];
	int a,b,c,d,e, pos = 0;

	for(a=0; a<P; a++)
		for(b=0; b<M; b++)
			for(c=0; c<F; c++)
				for(d=0; d<Q; d++)
					for(e=0; e<B; e++){
						total[pos] = arP[a] + arM[b] + arF[c] + arQ[d] + arB[e];
						pos++;
					}

	quickSort(total, 0, pos-1);

	int t = 0;
	int x;

	scanf("%d", &x);

	for(i=0; i<x; i++)
		t+=total[i];

	printf("%d\n", t);

	return 0;
}

void trocaValores(int* a, int* b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}
 
int divide(int vec[], int esquerdo, int direito)
{
    int i, j;
 
    i = esquerdo;
    for (j = esquerdo + 1; j <= direito; ++j)
    {
        if (vec[j] > vec[esquerdo]) /* Crescente */
        {
            ++i;
            trocaValores(&vec[i], &vec[j]);
        }
    }
    trocaValores(&vec[esquerdo], &vec[i]);
 
    return i;
}
 
void quickSort(int vec[], int esquerdo, int direito)
{
    int r;
 
    if (direito > esquerdo)
    {
        r = divide(vec, esquerdo, direito);
        quickSort(vec, esquerdo, r - 1);
        quickSort(vec, r + 1, direito);
    }
}