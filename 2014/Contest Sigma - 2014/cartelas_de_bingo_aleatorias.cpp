#include <iostream>

using namespace std;

int main()
{
	int x, num[24], i, j, intervalo[5];
	int OK;

	while (cin >> x)
	{
		num[0] = x;
		for(i=1; i<24; i++)
			cin >> num[i];
		for(i=0; i<5; i++)
			intervalo[i]=0;

		OK = 1;
		for (i=0; i<24; i++)
		{
			intervalo[(num[i]-1)/15]++;

			if (OK){
				if (i==0 || i==5 || i==10 || i==14 |i==19)
					if (num[i]>15 || num[i]<0)
						OK = 0;
				if (i==1 || i==6 || i==11 || i==15 |i==20)
					if (num[i]>30 || num[i]<15)
						OK = 0;
				if (i==2 || i==7 || i==16 |i==21)
					if (num[i]>45 || num[i]<30)
						OK = 0;
				if (i==3 || i==8 || i==12 || i==17 |i==22)
					if (num[i]>60 || num[i]<45)
						OK = 0;
				if (i==4 || i==9 || i==13 || i==18 |i==23)
					if (num[i]>75 || num[i]<60)
						OK = 0;
			}
		}

		if (OK==1)
			cout << "OK\n";
		else {
			if (intervalo[0]!=5 || intervalo[1] != 5 || intervalo[2]!=4 || intervalo[3] != 5 || intervalo[4]!=5)
				cout << "DESCARTAVEL\n";
			else
				cout << "RECICLAVEL\n";
		}

	}

	return 0;
}