#include <iostream>
#include <stdio.h>
#include <string.h>
#include <list>

#define MAX_V 1010
using namespace std;

list<int> vertex[MAX_V];
bool visited[MAX_V];
void dfs(int ini);

int main()
{
    int T, i, j, p, a, b, total;
    char str[20];

    while(scanf("%d", &T)!=EOF)
    {
        if(!T) break;

        for(i=0; i<MAX_V; i++)
            vertex[i].clear();
        memset(visited, 0, MAX_V);

        for(i=0; i<T; i++){
            scanf("%s", str);
            a = 0;
            p = 1;
            for(j=strlen(str)-2; str[j]!=','; j--){
                a+=(str[j]-'0')*p;
                p*=10;
            }
            b = 0;
            p = 1;
            for(j=j-1; str[j]!='('; j--){
                b+=(str[j]-'0')*p;
                p*=10;
            }
            
            vertex[a].push_back(b);
            vertex[b].push_back(a);
        }

        total = 0;
        dfs(1);
        for(i=0; i<MAX_V; i++)
            if(visited[i])
                total++;
        printf("%d\n", total==0?1:total);
    }

    return 0;
}

void dfs(int ini)
{
    list<int>::iterator it;
    visited[ini] = 1;

    for(it=vertex[ini].begin(); it!=vertex[ini].end(); it++){
        if(!visited[*it])
            dfs(*it);
    }

}