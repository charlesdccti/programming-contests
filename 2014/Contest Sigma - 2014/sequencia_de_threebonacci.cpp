#include <stdio.h>
#include <math.h>

typedef unsigned long long ull;

int pelomenos3(ull x);
int divisivel3(ull x);

int main()
{
    ull n, i;
    ull ant = 1, atu = 1, prox;
    ull fib[60];

    i=0;
    while (i<60) {
        prox = ant + atu;
        ant = atu;
        atu = prox;
        if (pelomenos3(atu)==1 || divisivel3(atu)==1 ){
            fib[i] = atu;
            i++;
        }  
    }


    while (scanf("%d", &n) != EOF)
    {
            printf("%llu\n",fib[n-1]);
    }
    return 0;
}

int pelomenos3(ull x)
{
    ull a;
    while (x!=0) {
        a = x%10;
        x = x/10;
        if (a==3)
            return 1;
        }
    return 0;
}

int divisivel3(ull x)
{
    ull t = 0;

    while (x!=0) {
        t += x%10;
        x = x/10;
    }

    if(t%3==0)
        return 1;
    else
        return 0;
}
