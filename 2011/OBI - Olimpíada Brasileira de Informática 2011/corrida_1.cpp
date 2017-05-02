#include <bits/stdc++.h>

using namespace std;
    
int main()
{
    int n, ans, m, x;

    cin >> n >> m;

    int A = 1e09;
    for (int i = 0; i < n; i++) {
        int s = 0;
        for (int j = 0; j < m; j++) {
            cin >> x; 
            s += x;
        }
        
        if (s < A) { 
            A = s;
            ans = i + 1;
        }
    }

    cout << ans << endl;

    return 0;
}