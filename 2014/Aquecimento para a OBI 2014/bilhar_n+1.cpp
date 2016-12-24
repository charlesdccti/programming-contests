#include <iostream>
#include <math.h>

using namespace std;
typedef long long int lli;

struct ponto
{
    double x, y;
    ponto(){}
    ponto(double _x, double _y) : x(_x), y(_y){}
};

lli dist(ponto a, ponto b);

int main()
{
    double xBranca, yBranca, xOutra, yOutra;
    lli menor, distancia;
    int bola, i, C, j, N;

    cin >> C;
    for(i=0; i<C; i++)
    {
        cin >> N;
        cin >> xBranca >> yBranca;
        ponto Branca(xBranca, yBranca);

        menor = 10000000000;
        for(j=0; j<N; j++){
            cin >> xOutra >> yOutra;
            ponto Outra(xOutra, yOutra);
            distancia = dist(Branca, Outra);
            //cout << "dist:" << distancia << endl;
            if(distancia < menor){
                menor = distancia;
                bola = j+1;
            }
        }

        cout << bola << endl;
    }

    return 0;
}

lli dist(ponto a, ponto b)
{
    double dx = a.x - b.x;
    double dy = a.y - b.y;

    return 100*sqrt(dx*dx+dy*dy);
}