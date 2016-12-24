#include<stdio.h>

int MDC(int, int);

int main()
{
    int x, y, z;
    
    while(scanf("%d %d %d", &x, &y, &z) != EOF)
    {
        if(x*x + y*y == z*z || x*x + z*z == y*y || y*y + z*z == x*x){
            if(MDC(x,MDC(y,z))==1)
                printf("tripla pitagorica primitiva\n");
            else
                printf("tripla pitagorica\n");
        } else {
            printf("tripla\n");
        }   
    }
    
    return 0;
}

int MDC(int x, int y)
{
    int divisor;
    int dividendo;
    int resto = 1;
    
    if(x>y){
        dividendo = x;
        divisor = y;
    } else {
        dividendo = y;
        divisor = x;
    }
    
    while(resto!=0){
        resto = dividendo%divisor;
        dividendo = divisor;
        divisor = resto;
    }
    
    return dividendo;
}