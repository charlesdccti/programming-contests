#include <iostream>
#include <math.h>

using namespace std;

typedef long long ull;

bool isPermutation(ull a, ull b);

int main()
{
	ull i, x, y;
	int q = 0;

	cin >> x;
	for (i=sqrt(x); i<=sqrt(x*11); i++){
		y = i*i - x;
		if (isPermutation(y,x)){
			q++;
		}
	}

	cout << q << endl;

	return 0;
}

bool isPermutation(ull a, ull b)
{
	int ar_a[10];
	int ar_b[10];
	int i, qa, qb;
	ull copy_a = a, copy_b = b;

	for (i=0; i<10; i++)
		ar_a[i] = ar_b[i] = 0;

	for (qa=0; copy_a!=0; qa++)
		copy_a = copy_a/10;
	for (qb=0; copy_b!=0; qb++)
		copy_b = copy_b/10;
	
	if (qa!=qb)
		return 0;

	for (i=0; a!=0; i++){
		ar_a[a%10]++;
		a = a/10;
		ar_b[b%10]++;
		b = b/10;
	}
	
	for (i=0; i<10; i++){
		if (ar_a[i] != ar_b[i])
			return 0;
	}

	return 1;
}