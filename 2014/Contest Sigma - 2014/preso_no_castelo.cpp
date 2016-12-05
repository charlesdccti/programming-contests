#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	list<int> G[1001], key[1001];
	int N, M, u, v, f, k[1001], vis[1001];

	while (cin >> N >> M)
	{
		for (int i = 0; i < 1001; i++) {
			G[i].clear();
			key[i].clear();
		}

		for (int i = 0; i < M; i++) {
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}

		for (int i = 2; i <= N; i++) {
			cin >> u;
			key[u].push_back(i);
		}
		
		memset(vis, -1, sizeof vis);
		memset(k, 0, sizeof k);

		queue<int> Q;
		Q.push(1);
		k[1] = 1;

		while (!Q.empty())
		{
			f = Q.front();
			Q.pop();
			if(vis[f] == 1) continue;
			
			vis[f] = 1;
			N--;

			for (list<int>::iterator it = key[f].begin();
				it != key[f].end(); it++) {
				k[*it] = 1; //getting key
				if (vis[*it] == 0)
					Q.push(*it);
			}


			for (list<int>::iterator it = G[f].begin();
				it != G[f].end(); it++) {
				if (vis[*it] == -1) vis[*it] = 0;
				if (vis[*it] != 1 && k[*it]) Q.push(*it); 
			}
		}

		cout << (!N ? "sim" : "nao") << endl;

	}

	return 0;
}