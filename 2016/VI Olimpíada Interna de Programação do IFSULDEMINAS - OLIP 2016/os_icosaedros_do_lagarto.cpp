#include <bits/stdc++.h>

#define fi first
#define se second
#define EPS 1e-9

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

inline double dist(ll x, ll y, ll x2, ll y2) {
	return sqrt((x-x2)*(x-x2) + (y-y2)*(y-y2));
}

int main()
{
	int c;
	ll x, y, a, b, e;
	int v[6] = {1, 2, 3, 5, 6, 7};
	int f[6];
	ii coord[8];

	cin >> c;
	for (int kk = 1; kk <=c ; kk++)
	{
		cin >> x >> y;
		for (int i = 0; i < 6; i++) 
		{
			cin >> a >> b >> e;
			coord[a] = ii(b, e);
		}

		double dist_min = 9999999999999.0;
		do {
			int act_x = x, act_y = y;
			double d = 0;
			for (int i = 0; i < 6; i++) 
			{
				d += dist(act_x, act_y, coord[v[i]].fi, coord[v[i]].se);
				act_x = coord[v[i]].fi;
				act_y = coord[v[i]].se;
			}
			d += dist(x, y, coord[v[5]].fi, coord[v[5]].se);

			if (d - dist_min + EPS < 0) 
			{
				dist_min = d;
				for (int i = 0; i < 6; i++) f[i] = v[i];
			}
		} while (next_permutation(v, v+6));


		cout << "Caso " << kk << ":\n"; 
		cout << "4->"; 
		for (int i = 0; i < 6; i++) 
			cout << f[i] << "->"; 
		cout << "4: ";
		cout << setprecision(5) << fixed << dist_min << endl;
	}

    return 0;
}