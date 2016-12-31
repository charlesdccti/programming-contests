#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;

ll power(ll b, ll e) {
    if(e == 0) return 1;
    else return b * power(b, e-1);
}
 
int main() {
 
    ll t = 1, n;
    
    while(cin >> n && n) {
        cout << "Teste " << t++ << endl;
        cout << power(2, n) - 1 << endl << endl;
    }
    
 
    return 0;
}