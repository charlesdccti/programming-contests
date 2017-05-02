#include <bits/stdc++.h>

using namespace std;

void dfs(int n);

vector<int> g[50000];
int v[50000] = {0};
int dg[50000] = {0};
bool cycle = false;

int main()
{
    int n, m;
    cin >> n >> m;

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        dg[b]++;
    }

    for (int i = 0; i < n; i++)
        if (!v[i]) dfs(i);

    if (!cycle)
    {
        priority_queue<int, vector<int>, greater<int> > q;

        for (int i = 0; i < n; i++)
            if (!dg[i]) q.push(i);

        while (!q.empty())
        {
            int u = q.top(); q.pop();
            cout << u << endl;

            for (auto it = g[u].begin(); it != g[u].end(); it++)
                if (--(dg[*it]) == 0) q.push(*it);
        }
    }
    else cout << "*" << endl;

    return 0;
}

void dfs(int n)
{
    v[n] = 1;

    for (auto it = g[n].begin(); it != g[n].end(); it++)
    {
        if (v[*it] == 1)
        {
            cycle = true;
            return;
        }
        else if (v[*it] == 0)
        {
            dfs(*it);
        }
    }

    v[n] = 2;
}