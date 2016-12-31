#include <bits/stdc++.h>

using namespace std;

int main()
{
    int V, c = 1;

    while (cin >> V && V) {
        cout << "Teste " << c++ << endl;
        cout << V/50 << " ";
        V -= 50 * (V/50);
        cout << V/10 << " ";
        V -= 10 * (V/10);
        cout << V/5 << " ";
        V -= 5 * (V/5);
        cout << V << endl << endl;
    }

    return 0;
}