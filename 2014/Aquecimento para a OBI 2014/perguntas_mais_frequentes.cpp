#include <stdio.h>
 
int main()
{
    int n, k, aux, t;
    int i;
    int p[101];

    while (1)
    {
        scanf("%d %d", &n, &k);
    
        t = 0;
        for (i=0; i<101; i++)
            p[i] = 0;

        if (!n && !k)
            break;

        for (i=0; i<n; i++)
        {
            scanf("%d", &aux);
            p[aux]++;
        }

        for (i=0; i<101; i++)
        {
            if (k==0){
                if(p[i]>0)
                    t++;
            }else{
                if(p[i] >= k)
                    t++;
            }
        }

        printf("%d\n", t);
    }


    return 0;
}
