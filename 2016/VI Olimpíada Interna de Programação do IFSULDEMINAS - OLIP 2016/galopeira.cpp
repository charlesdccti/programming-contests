#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	string str;
	
	while (cin >> N) 
	{
		while (N--) 
		{ 
			cin >> str; 
			cout << fixed << setprecision(2) << str.size()/100.0 << endl; 
		}
	}

    return 0;
}
