#include <bits/stdc++.h>

using namespace std;

int main()
{
	int c, a, b;

	cin >> c;
	while (c--) 
	{
		cin >> a >> b;
		int x = a;
		while (x <= b) 
		{
			cout << x++;
		}
		
		string z;
		while (b >= a) 
		{
			z.clear();
			int b_cpy = b;
			while (b_cpy != 0) 
			{
				cout << b_cpy%10;
				b_cpy/=10;
			}
			b--;
		}
		cout << endl;
	}

 
    return 0;
}