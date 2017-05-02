#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n; cin >> n;
    int flags[50] = {0};

    for (int i = 0; i < n; i++)
    {
        int mine; cin >> mine;
        
        if (mine) for (int j = i - 1 >= 0 ? i - 1 : 0; j < n && j < i + 2; j++)
            flags[j]++;
    }

    for (int i = 0; i < n; i++)
        cout << flags[i] << endl;

    return 0;
}