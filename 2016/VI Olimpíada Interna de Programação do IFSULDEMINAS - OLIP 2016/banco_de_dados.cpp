#include <bits/stdc++.h>

#define cls(arr) memset(arr, 0, sizeof arr);

using namespace std;


typedef long long ll;

ll power(ll b, ll e) 
{ 
	return e == 0 ? 1 : b * power(b, e-1);
}

int main()
{
	int dp[14][6*13+3];
	cls(dp)

	for (int i = 1; i <= 6; i++) dp[1][i] = 1;
	for (int i = 2; i <= 13; i++) {
		for (int j = 1; j <= 6*i; j++) {
			for (int k = 1; k <= 6; k++) {
				if (j-k > 0)
					dp[i][j] += dp[i-1][j-k];
			}
		}
	}

	int c, s, d;
	cin >> c;
	while (c--) {
		cin >> s >> d;
		cout << setprecision(15) << fixed << (double)dp[d][s]/(double)power(6, d) << endl;
	}
 
    return 0;
}