#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
	ll v[18] = {0, 0, 1, 1, 1, 2, 2, 4, 8, 12, 96, 108, 10368, 
	            10476, 108615168, 108625644, 11798392572168192, 
	            11798392680793836 }; // + * 
	            
	int x; while (cin >> x) cout << v[x] << endl;

    return 0;
}