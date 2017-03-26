#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    int a, v, t = 1, count[101], x, y;

    while (cin >> a >> v && a)
    {
        memset(count, 0, sizeof count);

        cout << "Teste " << t++ << endl;
        while (v--){ cin >> x >> y; count[x]++; count[y]++; }
        int maxx = 0;
        for (int i = 1; i <= a; i++) maxx = max(maxx, count[i]);
    
        for (int i = 1; i <= a; i++)
            if (count[i] == maxx)
                cout << i << " ";
        cout << endl << endl;
    }


    return 0;
}
