#include <bits/stdc++.h>

using namespace std;

int main()
{
	string str, str1;
	int hash[256];

	while (cin >> str) 
	{
		getline(cin, str1);
		getline(cin, str1);

		memset(hash, 0, sizeof hash);
		for (int i = 0; str[i] != '\0'; i++) 
			hash[str[i]] = 1;

		int x = 0;
		for (int i = 0; str1[i] != '\0'; i++)
			if (hash[str1[i]]) x++;
		cout << x << endl;
	}

    return 0;
}
