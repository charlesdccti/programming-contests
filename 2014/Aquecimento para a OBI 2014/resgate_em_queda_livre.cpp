#include <iostream>
#include <list>
#include <cstdio>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

typedef pair<double, double> pdd;

struct Edge {
    int vertex1;
    int vertex2;
    double weight;
    Edge(int v1, int v2, double w) : vertex1(v1), vertex2(v2), weight(w) {}
};

struct Graph {
    vector<int> vertice;
    vector<Edge> edges;
    vector<pdd> coord;
};

unordered_map<int, int> PARENT;
unordered_map<int, int> RANK;

int find(int vertex) {
    if (PARENT[vertex] == vertex)
        return PARENT[vertex];
    else
        return find(PARENT[vertex]);
}

double MST(Graph &g) 
{
    vector<Edge> res;
    double total = 0;

    for (auto c : g.vertice) {
        PARENT[c] = c;
        RANK[c] = 0;
    }

    sort(g.edges.begin(), g.edges.end(), [](Edge x, Edge y) {return x.weight < y.weight;});   // O(E*log(E))

    for (Edge e : g.edges) {         // O(E)
        int root1 = find(e.vertex1);  // O(E) worst case
        int root2 = find(e.vertex2);
        if (root1 != root2) {
            res.push_back(e);
            if (RANK[root1] > RANK[root2]) {
                PARENT[root2] = root1;
                RANK[root1]++;
            } else {
                PARENT[root1] = root2;
                RANK[root2]++;
            }
        }
    }

    for (Edge e : res) {
        //cout << e.vertex1 << " -- " << e.vertex2 << "  " << e.weight << endl;
        total+=e.weight;
    }

    return total;
}

double dist(pdd a, pdd b)
{
    return sqrt(pow(a.first-b.first, 2)+pow(a.second-b.second, 2));
}

int main(){

    int T, n_vert, n_edge;
    double x, y, w;
    Graph g;

    scanf("%d", &T);
    for(int i=0; i<T; i++)
    {
        scanf("%d", &n_vert);

        g.vertice.clear();
        g.edges.clear();
        g.coord.clear();

        for(int j=0; j<n_vert; j++){
            g.vertice.push_back(j);
            scanf("%lf %lf", &x, &y);
            g.coord.push_back(pdd(x, y));
            for(int k=0; k<j; k++){
                w = dist(pdd(x,y), g.coord[k]);
                g.edges.push_back(Edge(j, k, w));
                //g.edges.push_back(Edge(k, j, w));
            }
        }

        double path = MST(g)/100.0;
        printf("%0.2lf\n", path);
    }

    return 0;
}