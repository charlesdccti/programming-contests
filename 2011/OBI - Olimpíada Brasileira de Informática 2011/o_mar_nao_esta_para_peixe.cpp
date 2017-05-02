#include <iostream>
#include <string.h>

using namespace std;

int sea[100][100];

int main()
{
    memset(sea, 0, 100 * 100 * 4);

    int n; cin >> n;
    int area = 0;

    while (n--)
    {
        int x0, x1, y0, y1;
        cin >> x0 >> x1 >> y0 >> y1;

        for (int x = x0; x < x1; x++)
            for (int y = y0; y < y1; y++)
                sea[x][y] = 1;
    }

    for (int x = 0; x < 100; x++)
        for (int y = 0; y < 100; y++)
            area += sea[x][y];

    cout << area << endl;
    return 0;
}