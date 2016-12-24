#include <stdio.h>

int main()
{
    int n;
    int i;
    float a, b;
    
    scanf("%d", &n);
    for (i=0; i<n; i++)
    {
        scanf("%f %f", &a, &b);
        printf("%d cm2\n", (int)(a*b/2));
    }

    return 0;
}