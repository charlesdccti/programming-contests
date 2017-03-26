#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

typedef pair <int, int> ii;

int main()
{
    int C, E, L, P, X, Y, T = 1;
    int G[51][51];
    int v[51];

    while (cin >> C >> E >> L >> P && C)
    {
        cout << "Teste " << T++ << endl;

        memset(G, 0, sizeof G);
        memset(v, 0, sizeof v);

        for (int i = 0; i < E; i++) {
            cin >> X >> Y;
            G[X][Y] = G[Y][X] = 1;
        }

        queue<ii> q;
        q.push(ii(0,L));
        v[L] = 1;
        vector<int> ans;

        while (!q.empty())
        {
            ii act = q.front(); q.pop();
            if (act.fi > P) continue; 
            if (act.se != L) ans.push_back(act.se);

            for (int i = 1; i <= C; i++) {
                if (G[act.se][i] && !v[i]) {
                    v[i] = 1;
                    q.push(ii(act.fi+1, i));
                }
            }

        }

        sort(ans.begin(), ans.end());

        for (int i = 0; i < ans.size(); i++) {
            //if (i != 0)   cout << " ";
            cout << ans[i] << " ";
        }

        cout << endl << endl;
    }


    return 0;
}