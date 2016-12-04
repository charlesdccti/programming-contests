#include <stdio.h>
#include <math.h>

#define EPS 0.0001

struct ponto{
	double x, y;
	ponto(){}
	ponto(double _x, double _y) : x(_x), y(_y) {}
};

struct quadr{ /* Representamos o quadrado por dois pontos */
	ponto inf, sup;
	quadr(){}
	quadr(ponto _inf, ponto _sup) : inf(_inf), sup(_sup) {}
};

quadr toquadr(ponto C, double L){
	return quadr(ponto(C.x - L/2.0, C.y - L/2.0), ponto(C.x + L/2.0, C.y + L/2.0));
}

double dist2pontos(ponto a, ponto b){
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

double distquadrado(quadr a, quadr b){
	if (a.inf.x > b.inf.x) return distquadrado(b, a);
	if (b.inf.x < a.sup.x || fabs(b.inf.x - a.sup.x < EPS))
	{
		if (b.inf.y > a.sup.y) return b.inf.y - a.sup.y;
		if (b.sup.y < a.inf.y) return a.inf.y - b.sup.y;
		return 0;
	}
	if (b.inf.y > a.sup.y) return dist2pontos(b.inf, a.sup);
	if (b.sup.y < a.inf.y) return dist2pontos(ponto(b.inf.x, b.sup.y), ponto(a.sup.x, a.inf.y));
	return b.inf.x - a.sup.x;
}

int main()
{
	double N, AAH, Xc, Yc, L;
	double Xc_A, Yc_A, L_A;
	int i;
	bool YEAH;

	while(scanf("%lf %lf", &N, &AAH)!=EOF)
	{
		YEAH = 1;
		scanf("%lf %lf %lf", &Xc, &Yc, &L);
		quadr A, B;
		A = toquadr(ponto(Xc, Yc), L);
		for(i=1; i<N; i++){
			scanf("%lf %lf %lf", &Xc_A, &Yc_A, &L_A);
			B = toquadr(ponto(Xc_A, Yc_A), L_A);
			if(distquadrado(A, B) > AAH)
				YEAH = 0;
			A = B;
		}

		if(YEAH) printf("YEAH\n");
		else printf("OUCH\n");
	}

	return 0;
}