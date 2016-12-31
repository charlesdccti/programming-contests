#include <bits/stdc++.h>

using namespace std;

int main()
{
    int V, c = 1;

    while (cin >> V && V) {
        cout << "Teste " << c++ << endl;
        int z = 1, x;
        while (V--) {
            cin >> x;
            if (x == z++) cout << x << endl << endl;
        }
    }

    return 0;
}