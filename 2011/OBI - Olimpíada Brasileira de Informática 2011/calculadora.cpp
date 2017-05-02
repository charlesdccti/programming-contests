#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

int value;
char op;


int main()
{
    int N;
    int M[10]; memset(M, 0, sizeof M);
    
    cin >> N;
    while(N--) {
        cin >> value >> op;
        if (op == '*') {
            if (value == 4) M[2]+=2;
            else if (value == 6) { M[2]++; M[3]++; }
            else if (value == 8) M[2]+=3;
            else if (value == 9) M[3]+=2;
            else M[value]++;
        }
        else
            if (value == 4) M[2]-=2;
            else if (value == 6) { M[2]--; M[3]--; }
            else if (value == 8) M[2]-=3;
            else if (value == 9) M[3]-=2;
            else M[value]--;
    }

    if (M[0] != 0) cout << "0\n";
    else {
        int ans = 1;
        for (int i = 1; i <= 9; i++)
            ans *= pow(i, M[i]);
        cout << ans << endl;
    }



    return 0;
}
