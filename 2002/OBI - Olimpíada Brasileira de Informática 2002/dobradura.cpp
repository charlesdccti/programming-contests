#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n[16], v, p = 1, t = 1;

    for (int i = 0; i <= 15; i++) 
    {
        n[i] = (p + 1) * (p + 1);
        p *= 2;
    }

    while (cin >> v && v != -1)
    {
        cout << "Teste " << t++ << endl << n[v] << endl << endl;
    }


    return 0;
}

