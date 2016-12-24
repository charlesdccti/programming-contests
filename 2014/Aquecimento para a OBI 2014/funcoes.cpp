#include <stdio.h>

int main()
{
        
    int x, y;
    int n, i;
    int r, b, c;
    
    scanf("%d", &n);
    for (i=0; i<n; i++)
    {
        scanf("%d %d", &x, &y);
        r = 9*x*x + y*y;
        b = 2*x*x + 25*y*y;
        c = -100*x + y*y*y;
        
        if (r > b && r > c)
            printf("Rafael ganhou\n");
        if (c > b && c > r)
            printf("Carlos ganhou\n");
        if (b > r && b > c)
            printf("Beto ganhou\n");
    }

    return 0;
}