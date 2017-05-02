#include <bits/stdc++.h>

using namespace std;
    
int main()
{
    int N;
    int v[100000];

    cin >> N; for (int i = 0; i < N; i++) cin >> v[i];

    if (N == 1) { cout << "1\n"; return 0; }
    
    int ans = 1;
    int rs = v[1] - v[0];
    for (int i = 1; i < N - 1; i++) 
    {
        if (v[i+1] - v[i] != rs) {
            if (i + 2 < N) {
                rs = v[i+2] - v[i+1];
            }
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}