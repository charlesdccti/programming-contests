#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int main()
{
    int N, C, M, c = 1, mmax;
    vector<ii> v;

    while (cin >> N && N)
    {
        cout << "Turma " << c++ << endl;
        v.clear();
        mmax = 0;
        while (N--) {
            cin >> C >> M;
            v.push_back(ii(C, M));
            mmax = max(mmax, M);
        }


        for (int i = 0; i < v.size(); i++)
            if (v[i].second == mmax)
                cout << v[i].first << " ";
        cout << endl << endl;
    }

    return 0;
}