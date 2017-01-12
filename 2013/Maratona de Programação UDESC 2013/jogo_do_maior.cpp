#include<stdio.h>

int main()
{
    int n, i, j;
    int x, y, a, b;
    
    while(1){
        scanf("%d", &n);
        if(!n)
            break;
        x = y = 0;
        for(i=0; i<n; i++)
        {
            scanf("%d %d", &a, &b);
            if(a>b) x++;
            if(b>a) y++;
        }
        printf("%d %d\n", x, y);
    }
        
    return 0;
}
