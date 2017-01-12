#include <stdio.h>

typedef unsigned long long ull;

int main()
{
    ull n, q, x;

    while(scanf("%llu", &n))
    {
        q = 0;
        if(!n) 
            break;

        while(n>1){
            if(n%3==0)
                q+=n/3;
            if(n%3==1){
                q+= (n/3)-1;
                x = n - 3*((n/3)-1);
                q+= x/2;
            }
            if(n%3==2){
                q+= n/3;
                x = n - 3*(n/3);
                q+= x/2;
            }
            if(n%3==0)
                n = n/3;
            else 
                n = n/3 +1; 
        }


        printf("%llu\n", q);
    }


    return 0;
}