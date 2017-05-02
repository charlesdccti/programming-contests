#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

typedef pair <int, int> ii;
typedef pair <int, ii> iii;

iii pis[100];
int G[100][100], N, K, X, Y, vis[100][100];

bool isValid(int a, int b) {
    if (a >= 0 && a < N && b >= 0 && b < N)
        return true;
    return false;
}

int main()
{
    cin >> N >> K;
    for (int i = 0; i < K; i++)
        cin >> pis[i].se.fi >> pis[i].se.se >> pis[i].fi;

    for (int i = 0; i < K; i++)
        if(pis[i].fi == 0) {
            cout << pis[i].se.fi << " " << pis[i].se.se << endl;
            return 0;
        }

    memset(G, 0, sizeof G);

    for (int i = 0; i < K; i++) {
        memset(vis, 0, sizeof vis);
        for (int j = 0; j <= pis[i].fi; j++) 
        {
            int x = pis[i].se.fi;
            int y = pis[i].se.se;
            int q = pis[i].fi;

            if(isValid(x + (q - j), y + j) && !vis[x + (q - j)][y + j]) 
            {
                G[x + (q - j)][ y + j]++;
                vis[x + (q - j)][y + j] = 1;
            }

            if(isValid(x - (q - j), y + j) && !vis[x - (q - j)][y + j]) 
            {
                G[x - (q - j)][ y + j]++;
                vis[x - (q - j)][y + j] = 1;
            }

            if(isValid(x + (q - j), y - j) && !vis[x + (q - j)][y - j]) 
            {
                G[x + (q - j)][ y - j]++;
                vis[x + (q - j)][y - j] = 1;
            }

            if(isValid(x - (q - j), y - j) && !vis[x - (q - j)][y - j]) 
            {
                G[x - (q - j)][ y - j]++;
                vis[x - (q - j)][y - j] = 1;
            }
        }
    }

    /*for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << G[i][j] << " ";
        cout << endl;
    }*/

    iii ans = iii(0, ii(0, 0));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if(G[i][j] == K) {
                ans.fi++;
                ans.se.fi = i;
                ans.se.se = j;
            }

    if(ans.fi == 1) {
        cout << ans.se.fi << " " << ans.se.se << endl;
    } else {
        cout << "-1 -1\n";
    }

    return 0;
}