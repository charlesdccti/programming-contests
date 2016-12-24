#include <vector>
#include <string.h>
#include <cmath>
#include <iostream>
#include <cstdio>
#include <utility>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

bool visitado[11000];
int inverter(int n);

int main()
{
    queue<pii> q;
    int T, i, a, b;
    scanf("%d", &T);
    for (i=0; i<T; i++)
    {
        scanf("%d %d", &a, &b);

        memset(visitado, false, sizeof(visitado));
        while (!q.empty()) q.pop();
        
        q.push(make_pair(a, 0));

        while (!q.empty()) 
        {
            pii u = q.front();
            q.pop();

            if (u.first >= 11000) continue; //numeros inuteis
            if (visitado[u.first] == true) continue; //evita ciclos
            visitado[u.first] = true;

            if (u.first == b) {
                printf("%d\n", u.second);
                break;
            }

            q.push(pii( u.first+1, u.second+1 ));
            q.push(pii( inverter(u.first), u.second+1 ));
        }
    }

    return 0;
}

int inverter(int n)
{
    int n_cpy = n;
    int t = 0;
    int inv = 0;

    while (n_cpy != 0){ 
        n_cpy/=10; 
        t++;
    }
    
    while (t>0){ 
        inv+=(n%10)*pow(10,t-1); 
        n/=10;
        t--;
    }
    
    return inv;
}