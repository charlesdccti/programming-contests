#include <stdio.h>

int main()
{    
    int n, i, j, m, a;
    
    scanf("%d", &n);
    for (i=0; i<n; i++)
    {
        scanf("%d", &m);
        for (j=0; j<m; j++)
        {
            scanf("%d", &a);
            switch (a){
                case 1: printf("Rolien\n"); break;
                case 2: printf("Naej\n"); break;
                case 3: printf("Elehcim\n"); break;
                case 4: printf("Odranoel\n"); break;
            }
        }
    }

    return 0;
}
