#include <bits/stdc++.h>

using namespace std;
    
int main()
{
    int a[3];

    cin >> a[0] >> a[1] >> a[2];

    sort(a, a + 3);

    if(a[0] + a[1] > a[2]) {
        if(a[0]*a[0] + a[1]*a[1] == a[2]*a[2])
            cout << "r\n";
        else if(a[0]*a[0] + a[1]*a[1] > a[2]*a[2])
            cout << "a\n";
        else
            cout << "o\n";
    } else {
        cout << "n\n";
    }

    return 0;
}