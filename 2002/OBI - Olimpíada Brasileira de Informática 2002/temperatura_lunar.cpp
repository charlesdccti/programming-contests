#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

typedef pair <int, int> ii;


int main()
{
    ios::sync_with_stdio(false);
    int v[10000], n, m, t = 1;

    while (cin >> n >> m && n) {
        cout << "Teste " << t++ << endl;
        for (int i = 0; i < n; i++)
            cin >> v[i];

        int s = 0;
        for (int j = 0; j < m; j++)
            s += v[j];

        int maxx = s / m;
        int minn = s / m;

        for(int j = 0; j < n-m; j++) {
            s -= v[j];
            s += v[m+j];
            maxx = max(maxx, s / m);
            minn = min(minn, s / m);
        }

        cout << minn << " " << maxx << endl << endl;
    }


    return 0;
}
