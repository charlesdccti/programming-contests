#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, a, b, c;
	cin >> n;
	while(n--)
	{
		cin >> a >> b >> c;
		printf("%02d:%02d - A porta ", a, b);
		c == 1 ? cout << "abriu!\n" : cout << "fechou!\n";
	}

    return 0;
}