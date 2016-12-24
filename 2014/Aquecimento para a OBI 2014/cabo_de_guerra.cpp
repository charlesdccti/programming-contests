#include <stdio.h>
#include <iostream>
#include <string>
  
using namespace std;
  
typedef long long  int lli;
 
#define MAX 100100
  
int main()
{
    int T, i, j;
    lli A, B;
    int inicio, meio, fim, size;
    int partic[MAX];
    char nome[MAX][15];
  
    while(scanf("%d", &T)!=EOF && T)
    { 
        for(i=0; i<T; i++){
            partic[i] = 0;
            scanf("%s", nome[i]);
            for(j=0; nome[i][j]!='\0'; j++)
                partic[i]+=nome[i][j];
        }
  
        inicio = 0;
        fim = T-1;
  
        while(inicio<=fim){
            meio = (inicio + fim )/2;
            A = B = 0;
            for(i=0; i<meio; i++) A+=partic[i]*(meio-i);
            for(i=T-1; i>=meio; i--) B+=partic[i]*(i-meio+1);
            if(A==B){ printf("%s\n",nome[meio-1]); break;}
            else if(A>B) fim = meio-1;
            else inicio = meio+1;
        }
  
        if(A!=B) printf("Impossibilidade de empate.\n");
  
    }
  
    return 0;
}