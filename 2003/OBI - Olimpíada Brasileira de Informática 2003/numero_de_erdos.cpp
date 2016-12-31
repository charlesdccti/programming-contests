#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

typedef pair <int, int> ii;
typedef pair <string, char> sc;

bool cmp(const string& u, const string& v)
{
    return u.substr(3) + u.substr(0, 2) < v.substr(3) + v.substr(0, 2);
}

int main()
{
    int t = 0;
    int n;
    string line;

    while (cin >> n && n)
    {
        getline(cin, line);
        map<string, set<string> > G;
        set<string> allA;
        
        for (int i = 0; i < n; i++)
        {
            getline(cin, line);
            stringstream ss(line.substr(0, line.size() -1));
            vector<string> A;
            
            while (getline(ss, line, ',') ) {
                if(line[0] != ' ') A.push_back(line);
                else A.push_back(line.substr(1));
            }
            
            for (int j = 0; j < A.size(); j++)
            {
                allA.insert(A[j]);
                for (int k = 0; k < A.size(); k++)        
                    if (j != k)
                        G[A[j]].insert(A[k]);
            }
        }

        queue<pair<string, int> > q;
        map<string, int> nd;
        
        q.push(make_pair("P. Erdos", 0));
        
        while (!q.empty())
        {
            pair<string, int> at = q.front();
            q.pop();
            
            if (nd.count(at.first) == 0) {
                nd[at.first] = at.second;
                for (set<string>::iterator it = G[at.first].begin(); 
                    it != G[at.first].end(); it++)
                    q.push(make_pair(*it, at.second + 1));
            }
        }
        
        vector<string> A;
        for (set<string>::iterator it = allA.begin(); it != allA.end(); it++)
            A.push_back(*it);
        sort(A.begin(), A.end(), cmp);
        
        cout << "Teste " << ++t << endl;
        for (int i = 0; i < A.size(); i++) 
        {
            if (A[i] != "P. Erdos") {
                if (nd.count(A[i])) cout << A[i] << ": " << nd[A[i]] << endl;
                else cout << A[i] << ": infinito" << endl;
            }
        }
        cout << endl;
    }
    return 0;
}

