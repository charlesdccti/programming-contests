#include <bits/stdc++.h>

using namespace std;

int main()
{
	string a;
	int f;
	while (cin >> a) {
		int x = 1;
		f = 0;
		for (int i = a.size() - 1; i >= 0; i--) {
			if (i-x >= 0) {
				if (a.substr(i, x) == a.substr(i-x, x)) {
					cout << a.substr(0, i) << endl;
					f = 1;
				}
			}
			else break;
			x++;
		}
		if (!f) cout << a << endl;
	}

    return 0;
}