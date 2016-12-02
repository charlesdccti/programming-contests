#include <bits/stdc++.h>

#define cls(arr) memset(arr, 0, sizeof arr);

using namespace std;

int w[101][101];
int v[101][101];
int m, n, x, y, z, c;

void floodfill(int xx, int yy, int vv) {
	if(vv == 1) return;
	
	for (int i = xx; i <= xx + (10-vv)*2-1; i++) if (i < 101 && i > 0 && yy > 0 && yy < 101){ w[i][yy] += vv; v[i][yy] = 1; }
	for (int i = xx+1; i <= xx + (10-vv)*2; i++) if (i < 101 && i > 0 && yy + (10-vv)*2 < 101 && yy + (10-vv)*2 > 0){ w[i][yy + (10-vv)*2] += vv; v[i][yy + (10-vv)*2] = 1; }
	for (int i = yy+1; i <= yy + (10-vv)*2; i++) if (i < 101 && i > 0 && xx > 0 && xx < 101){ w[xx][i] += vv; v[xx][i] = 1; }
	for (int i = yy; i <= yy + (10-vv)*2-1; i++) if (i < 101 && i > 0 && xx + (10-vv)*2 < 101 && xx + (10-vv)*2 > 0){ w[xx + (10-vv)*2][i] += vv; v[xx + (10-vv)*2][i] = 1; }
	floodfill(xx-1, yy-1, vv-1);
}


int main()
{

	cin >> c;
	for (int k = 1; k <= c; k++)
	{
		cls(w)
		cin >> m >> n >> x >> y;
		for (int i = 1; i <= m; i++)  
			for (int j = 1; j <= n; j++)  
				cin >> w[i][j];
		w[x][y] += 10;
		
		cls(v)
		v[x][y] = 1;
		floodfill(x-1, y-1, 9);
		cout << "Parede " << k << ":\n";
		for (int i = 1; i <= m; i++) 
			for (int j = 1; j <= n; j++) 
				if (v[i][j] == 0) w[i][j] += 1;

		for (int i = 1; i <= m; i++) { 
			for (int j = 1; j <= n; j++) { 
				if (j!=1) 
					cout << " "; 
				cout << w[i][j]; 
			} cout << endl; 
		}
	}


    return 0;
}