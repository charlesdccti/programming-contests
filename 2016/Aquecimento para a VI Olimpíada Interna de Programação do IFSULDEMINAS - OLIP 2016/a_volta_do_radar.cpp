#include <iostream>
 
using namespace std;
 
int main() {
 
    int T, a;
    while(cin >> T && T) { while(T--){cin >> a; 
        int x = a%2 ? a*2-1 : a* 2 - 2;
        cout << x << endl;} 
    }
 
    return 0;
}