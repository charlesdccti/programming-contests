#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

typedef pair<int, int> ii; //pos(x,y)
typedef pair<int, ii> iii; //path pos(x,y)

int G[17][17];
int N, M, K;
string tab[101];
int vis[101][101];
ii pecas[17]; //0 cavalo inicial
int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};
int dp[17][1 << 17];

int isvalid(int x, int y) {
    return !(x < 0 || x >= N || y < 0 || y > M || tab[x][y] == '#');
}

int getid(int x, int y) {
    for(int j = 0; j <= K; j++)
        if(pecas[j].fi == x && pecas[j].se == y)
            return j;
    return -1;
}

int tsp(int pos, int bitmask) {
    if(bitmask == ((1 << (K+1)) - 1)) return G[pos][0];
    if(dp[pos][bitmask] != -1) return dp[pos][bitmask];

    int ans = 1000000;
    for(int i = 0; i <= K; i++) 
        if(!(bitmask & (1 << i))) 
            ans = min(ans, G[pos][i] + tsp(i, bitmask | (1 << i)));
    
    return dp[pos][bitmask] = ans;
}

int main()
{
    while(cin >> N >> M >> K && N)
    {
        for(int i = 0; i < N; i++)
            cin >> tab[i];

        int cont = 1;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++) {
                if(tab[i][j] == 'P')
                    pecas[cont++] = ii(i, j);
                if(tab[i][j] == 'C')
                    pecas[0] = ii(i, j);
            }

        for(int i = 0; i <= K; i++) //pra cada peça
        {
            memset(vis, 0, sizeof vis);
            queue<iii> Q;

            Q.push(iii(0, pecas[i]));
            vis[pecas[i].fi][pecas[i].se] = 1;
            
            while(!Q.empty())
            {
                iii f = Q.front();
                Q.pop();

                for(int j = 0; j < 8; j++)
                {
                    int nx = f.se.fi + dx[j];
                    int ny = f.se.se + dy[j];
                    if(isvalid(nx, ny) && !vis[nx][ny])
                    {
                        vis[nx][ny] = 1;
                        if(tab[nx][ny] == 'P' || tab[nx][ny] == 'C')
                            G[i][getid(nx, ny)] = f.fi + 1;
                        Q.push(iii(f.fi + 1, ii(nx, ny)));
                    }
                }
            }
        }

        memset(dp, -1, sizeof dp);
        cout << tsp(0, 1) << endl;

    }

    return 0;
}