#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;

int main()
{
    int n, v; cin >> n >> v;
    vector<ii> run;

    for (int i = 0; i < n; i++)
    {
        int total = 0;

        for (int j = 0; j < v; j++)
        {
            int val; cin >> val;
            total += val;
        }

        run.push_back(ii(total, i + 1));
    }

    sort (run.begin(), run.end());

    cout << run[0].second << endl;
    cout << run[1].second << endl;
    cout << run[2].second << endl;

    return 0;
}   