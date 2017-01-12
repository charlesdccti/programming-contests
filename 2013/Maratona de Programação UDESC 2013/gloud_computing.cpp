#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int N, M, Q, P, c;
    bool connect;
    string aux;
    set<string>servers[201];
    set<string>::iterator sit;
    vector<string>requisicoes;
    vector<string>::iterator vit;

    while(scanf("%d %d", &N, &M)!=EOF && N && M)
    {
        c = 0;

        for(int i=1; i<=N; i++){ 
            servers[i].clear();
            scanf("%d", &Q);
            for(int j=1; j<=Q; j++){
                cin >> aux;
                servers[i].insert(aux);
            }
        }

        for(int i=1; i<=M; i++){
            scanf("%d", &P);
            requisicoes.clear();
            for(int j=1; j<=P; j++){
                cin >> aux;
                requisicoes.push_back(aux);
            }

            for(int j=1; j<=N; j++){
                connect = 0;
                for(vit=requisicoes.begin(); vit!=requisicoes.end(); vit++){
                    if(servers[j].find(*vit) != servers[j].end()){
                        connect = 1;
                        break;
                    }
                }
                if(connect) c++;
            }
        }

        printf("%d\n", c);
    }

    return 0;
}