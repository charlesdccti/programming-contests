#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

typedef pair <int, int> ii;

int n, v[100];
bool dp[10101][101];

int main()
{
    int t = 1, x, y, sum;

    while (cin >> x >> y >> n && !(x == 0 && y == 0 && n == 0))
    {
        sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            sum += v[i];
        }       
    
        cout << "Teste " << t++ << endl;
        if (((x + y + sum) % 2 != 0) || 
            (x + sum < y) || (y + sum < x))
            cout << "N" << endl << endl;
        else {
            memset(dp, -1, sizeof dp);
            for (int i = 1; i <= sum; i++)
                dp[i][0] = false; //set empty
            for (int i = 0; i < n; i++)
                dp[0][i] = true; //sum is 0
            
            sum = (x + y + sum) / 2 - min(x, y);

            for (int i = 1; i <= sum; i++)
                for (int j = 1; j <= n; j++)
                {
                    dp[i][j] = dp[i][j-1]; //without item
                    if (i >= v[j-1]) //fit
                        dp[i][j] = dp[i][j] ||
                                   dp[i - v[j-1]][j-1];
                }
            cout << (dp[sum][n] ? "S" : "N") << endl << endl;
        }

    }

    return 0;
}
