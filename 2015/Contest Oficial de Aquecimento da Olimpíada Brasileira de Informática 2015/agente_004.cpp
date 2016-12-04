#include <iostream>
#include <stdio.h>
#include <list> //adjacency list
#include <utility> //pair make_pair
#include <string.h> //memset
#include <queue> //priority queue
 
#define DIST_MAX 100000000
#define MAX_V 10010
 
using namespace std;
 
typedef long long int lli;
typedef pair<lli, bool> pib;
typedef pair<lli, pib> piib; //v_dest weight whoknows
 
lli dist[MAX_V]; //distance
lli parent[MAX_V]; //parent node
lli n_vert;
list<piib> graph[MAX_V]; //graph
list<piib>::iterator it;
 
void Dijkstra(lli root, list<piib>* vertex, bool);
 
struct Node
{
public:
    lli a;
    Node(lli x){a = x;} //constructor
    bool operator<(const struct Node p2) const{
        return dist[a] > dist[p2.a];
    }
};
 
int main()
{
    lli rC, rD, qB; //rota conhecida/desconhida
    lli v1, v2, pB[MAX_V], we; //auxilios posiçãoBandido
    lli o, d; //origem destino
    lli distBino, distStealer, q;
    while(scanf("%lld %lld %lld %lld", &n_vert, &rC, &rD, &qB) != EOF)
    {
        q = 0; 
        for(int i=0; i<rC; i++)
        {
            scanf("%lld %lld %lld", &v1, &v2, &we);
            graph[v1].push_back(make_pair(v2, make_pair(we,0)));
            graph[v2].push_back(make_pair(v1, make_pair(we,0)));
        }
 
        for(int i=0; i<rD; i++)
        {
            scanf("%lld %lld %lld", &v1, &v2, &we);
            graph[v1].push_back(make_pair(v2, make_pair(we,1)));
            graph[v2].push_back(make_pair(v1, make_pair(we,1)));
        }
 
        for(int i=0; i<qB; i++)
            scanf("%lld", &pB[i]);
 
        scanf("%lld %lld", &o, &d);
        Dijkstra(o, graph, 0);
        distBino = dist[d];
        Dijkstra(d, graph, 1);
        for(int i=0; i<qB; i++)
        {
            distStealer = dist[pB[i]];
            if(distBino >= distStealer)
                q++;
        }
 
        printf("%lld\n", q);

        for(int i=0; i<=n_vert; i++)
            graph[i].clear();
        memset(dist, 0, n_vert+1);
        memset(parent, 0, n_vert+1);
    }
 
    return 0;
}
 
void Dijkstra(lli root, list<piib>* vertex, bool know)
{   
    for(lli i=1; i<=n_vert; i++)
    {
        dist[i] = DIST_MAX;
        parent[i] = -1;
    }
    dist[root] = 0;
 
    priority_queue<Node> mypq;
    while(!mypq.empty()) 
        mypq.pop();
    mypq.push(root);
 
    lli v_dest, weight;
    lli act; //actual vertex
 
    while(!mypq.empty())
    {
        act = mypq.top().a;
        mypq.pop();
        for(it=vertex[act].begin(); it!=vertex[act].end(); it++) //similar to bfs
        {
        	if(it->second.second==0 || know)
        	{
	            v_dest = it->first;
	            weight = it->second.first;
	            if(dist[v_dest] > dist[act]+weight) //replace
	            {
	                parent[v_dest] = act;
	                dist[v_dest] = dist[act]+weight;
	                mypq.push(Node(v_dest));
	            }
        	}
        }
    }
}