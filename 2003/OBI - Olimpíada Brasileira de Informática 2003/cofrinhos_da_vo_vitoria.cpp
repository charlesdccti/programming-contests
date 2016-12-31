#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, J, Z, c = 1, v;

    while (cin >> N && N) {
        cout << "Teste " << c++ << endl;

        v = 0;
        while (N--) {
            cin >> J >> Z;
            v += J - Z;
            cout << v << endl;
        }
        
        cout << endl;
    }

    return 0;
}