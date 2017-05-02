#include <bits/stdc++.h>

using namespace std;

int main()
{
    int rocks_qt, frogs_qt;
    cin >> rocks_qt >> frogs_qt;
    bool rocks[rocks_qt];
    memset(rocks, false, sizeof rocks);
    pair<int, int> frog;
    while(frogs_qt--) {
        cin >> frog.first >> frog.second;
        for(int i = frog.first - 1; i < rocks_qt; i += frog.second)
            rocks[i] = true;
        for(int i = frog.first - 1; i >= 0; i -= frog.second)
            rocks[i] = true;
    }
    for(int i = 0; i < rocks_qt; i++)
        cout << rocks[i] << endl;
    return 0;
}
