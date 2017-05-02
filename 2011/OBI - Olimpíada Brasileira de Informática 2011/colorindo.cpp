#include <iostream>
#include <math.h>

using namespace std;

void dfs(int x, int y);

int walkX[8] = { -1,  0,  1, -1, 1, -1, 0, 1 };
int walkY[8] = { -1, -1, -1,  0, 0,  1, 1, 1 };

int board[201][201] = {0};
int rows, cols;
int area = 0;

int main()
{
    int x0, y0, k;
    cin >> rows >> cols >> x0 >> y0 >> k;

    while (k--)
    {
        int x, y; cin >> x >> y;
        board[x][y] = 1;
    }

    dfs(x0, y0);
    cout << area << endl;

    return 0;
}

void dfs(int x, int y)
{
    board[x][y] = 1;
    area++;

    for (int i = 0; i < 8; i++)
    {
        int x1 = x + walkX[i];
        int y1 = y + walkY[i];

        if (x1 > 0 && x1 <= rows && y1 > 0 && y1 <= cols && !board[x1][y1])
            dfs(x1, y1);
    }
}