#include <iostream>
#include <string>
#include <list>
#include <queue>
#include <vector>

using namespace std;

void clear(int V, int* vis, list<int>*G);

int main()
{
	int V, E, i, j, larg, dist;
	int p_e1, p_e2;
	bool e1_ok, e2_ok;
	string e1, e2;
	vector<string> org;
	vector<string>::iterator vit;

	while(cin >> V >> E)
	{
		list<int> Grafo[V];
		list<int>::iterator lit;
		int vis[V];

		/* Limpando */
		clear(V, vis, Grafo);
		org.clear();

		/* Populando o Grafo */
		org.push_back("Entrada");
		org.push_back("Saida");
		org.push_back("*");

		for(i=0; i<E; i++)
		{
			cin >> e1 >> e2;

			e1_ok = e2_ok = p_e1 = p_e2 = 0;
			for(vit=org.begin(); vit!=org.end(); vit++){
				if(*vit==e1) e1_ok = 1;
				if(*vit==e2) e2_ok = 1;
				if(e1_ok && e2_ok) break;
			}
			if(!e1_ok) org.push_back(e1);
			if(!e2_ok) org.push_back(e2); 

			for(j=0; j<org.size(); j++){
				if(org[j] == e1) p_e1 = j;
				if(org[j] == e2) p_e2 = j;
				if(p_e1!=0 && p_e2!=0) break;
			}
			
			Grafo[p_e1].push_back(p_e2);
			Grafo[p_e2].push_back(p_e1);
		}

		dist = 0;
		/* Realizando a busca em largura Entrada -> * */
		queue<int>fila;
		fila.push(0);
		larg = 0;
		while(!fila.empty()){
			if(!vis[fila.front()])
				vis[fila.front()] = larg++;
			for(lit=Grafo[fila.front()].begin(); lit!=Grafo[fila.front()].end(); lit++){
				if(!vis[*lit]){
					vis[*lit] = vis[fila.front()]+1;
					fila.push(*lit);
				}
			}
			if(vis[2]!=0)
				break;
			fila.pop();
		}

		dist+=vis[2];

		while(!fila.empty())
			fila.pop();
		for(i=0; i<V; i++)
			vis[i] = 0;

		/* Realizando a busca em largura Saída -> * */
		fila.push(1);
		larg = 0;

		while(!fila.empty()){
			if(!vis[fila.front()])
				vis[fila.front()] = larg++;
			for(lit=Grafo[fila.front()].begin(); lit!=Grafo[fila.front()].end(); lit++){
				if(!vis[*lit]){
					vis[*lit] = vis[fila.front()]+1;
					fila.push(*lit);
				}
			}
			if(vis[2]!=0)
				break;
			fila.pop();
		}

		dist+=vis[2];
		/* Imprimindo a distancia */
		cout << dist << endl;

		/*
		for(i=0; i<V; i++){
			cout << i << " - " << vis[i] << " - ";
			for(lit=Grafo[i].begin(); lit!=Grafo[i].end(); lit++)
				cout << *lit << " ";
			cout << endl;
		}
		*/
	}

	return 0;
}

void clear(int V, int* vis, list<int>*G)
{
	int i;
	for(i=0; i<V; i++)
		G[i].clear();
	for(i=0; i<V; i++)
		vis[i] = 0;
}