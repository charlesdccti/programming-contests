#include <bits/stdc++.h>

using namespace std;

int main()
{
	int c, a, b;
	string str;

	while (cin >> c)
	{
		c = c*2 - 1;
		int x = 0;
		while (c--) 
		{
			if (x%2 ==0) 
			{
				scanf("%dx%d", &a, &b);
				cout << a*b << "x"; 
				if(b != 2) 
					cout << b-1;
			} else {
				cin >> str;
				cout << " + ";
			}
			x++;
 		}
		
		cout << endl;
	}


    return 0;
}