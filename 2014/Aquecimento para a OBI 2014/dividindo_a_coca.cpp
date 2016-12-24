#include <iostream>
#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793
#define EPS 0.0001

using namespace std;
double findH(double b, double B, double h, double r);

int main()
{
    int i, C;
    double N, L, V, b, B, H;

    cin >> C;
    for(i=0; i<C; i++){
        cin >> N >> L;
        cin >> b >> B >> H;

        V = L/N;
        printf("%.02lf\n", findH(b, B, H, V));
    
    }

    return 0;
}

double findH(double b, double B, double h, double r)
{

    if(PI*h*(B*B+B*b+b*b)/3 - r > EPS)
    {
        return findH(b,(B+b)/2,h/2,r);
    }
    else if(PI*h*(B*B+B*b+b*b)/3 - r < -EPS)
    {
        r-=PI*h*(B*B+B*b+b*b)/3;
        B+=B-b;
        b=(B+b)/2;
        return findH(b,B,h,r)+h;
    }
    else
        return h;
}