#include <stdio.h>

int abs(int x){
    if(x<0)
        return -1*x;
    return x;
}

int main()
{
        
    int n, m, i, j;
    int a, b;
    int gp; //guarda posição
    int dif;
    
    scanf("%d" ,&n);
    for (i=0; i<n; i++)
    {
        scanf("%d %d", &a, &b);
        dif = 101;
        gp = 1;
        for (j=0; j<a; j++){
            scanf("%d", &m);
            if (abs(m-b) < dif){
                dif = abs(m-b);
                gp = j+1;
            }
        }
        printf("%d\n", gp);
    }

    return 0;
}