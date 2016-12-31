#include <bits/stdc++.h>

#define x first
#define y second
#define se first
#define id second

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, ii> rect;

rect flag = rect(ii(-1,-1), ii(-1,-1));

rect intersection(rect r1, rect r2)
{
    if (r1.se.y < r2.id.y || r2.se.y < r1.id.y ||
        r1.se.x > r2.id.x || r2.se.x > r1.id.x)       
        return rect(ii(-1,-1), ii(-1,-1));
 
    rect ans;

    ans.se.x = max(r1.se.x, r2.se.x);
    ans.se.y = min(r1.se.y, r2.se.y);
    ans.id.x = min(r1.id.x, r2.id.x);
    ans.id.y = max(r1.id.y, r2.id.y);

    return ans;
}

int main() 
{
    ios::sync_with_stdio(0);

    int n, c = 1;
    bool ans;
    rect r[2];

    while(cin >> n && n)
    {
        cin >> r[0].se.x >> r[0].se.y >> r[0].id.x >> r[0].id.y;
        ans = true;

        while(--n)
        {
            cin >> r[1].se.x >> r[1].se.y >> r[1].id.x >> r[1].id.y;
            r[0] = intersection(r[0], r[1]);
            if(r[0] == flag)
                ans = false;
        }

        cout << "Teste " << c++ << endl;
        if(ans) {
            cout << r[0].se.x << " " << r[0].se.y << " " << r[0].id.x
                 << " " << r[0].id.y << endl << endl;
        } else {
            cout << "nenhum" << endl << endl;
        }
    }


    return 0;
}
