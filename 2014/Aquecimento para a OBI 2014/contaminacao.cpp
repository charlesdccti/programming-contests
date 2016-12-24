#include <stdio.h>

#define MAX 100

char MAPA[MAX][MAX];
bool visited[MAX][MAX];

void Imprimir(int L, int C);
void contamine(int l, int c, int L, int C);

int main()
{
    int L, C, i, j;

    while(scanf("%d %d", &L, &C)!=EOF)
    {
        if(L==0 && C==0) break;

        for(i=0; i<L; i++)
            scanf("%s", MAPA[i]);
        
        //Imprimir(L, C);

        for(i=0; i<L; i++)
            for(j=0; j<C; j++)
                visited[i][j] = 0;

        for(i=0; i<L; i++)
            for(j=0; j<C; j++)
                if(MAPA[i][j]=='T'  && visited[i][j]==0)
                    contamine(i,j,L,C);
                

        Imprimir(L, C);
    }


    return 0;
}

void contamine(int l, int c, int L, int C)
{
    visited[l][c] = 1;

    if(l+1 < L){
        if(MAPA[l+1][c] == 'A' && visited[l+1][c]==0){
            MAPA[l+1][c] = 'T';
            contamine(l+1, c, L, C);
        }
    }

    if(l-1 >= 0){
        if(MAPA[l-1][c] == 'A' && visited[l-1][c]==0){
            MAPA[l-1][c] = 'T';
            contamine(l-1, c, L, C);
        }
    }

    if(c-1 >= 0){
        if(MAPA[l][c-1] == 'A' && visited[l][c-1]==0){
            MAPA[l][c-1] = 'T';
            contamine(l, c-1, L, C);
        }
    }

    if(c+1 < C){
        if(MAPA[l][c+1] == 'A' && visited[l][c+1]==0){
            MAPA[l][c+1] = 'T';
            contamine(l, c+1, L, C);
        }
    }
}

void Imprimir(int L, int C)
{
    int i, j;
    for(i=0; i<L; i++){
        for(j=0; j<C; j++)
            printf("%c", MAPA[i][j]);
        printf("\n");
    }
    printf("\n");
}