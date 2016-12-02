#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m, c;
	while (cin >> n >> m >> c && n) {
		string str[n];
		getline(cin, str[0]);
		for (int i = 0; i < n; i++) 
			getline(cin,str[i]);

		int p_x, p_y;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (str[i][j] == '<'){ str[i][j] = ' '; p_x = i; p_y = j;  break;}

		string mov;
		cin >> mov;
		int dir = 1; //1dir 2left 4up 3 down
		int p = 0;
		//cout << mov << endl;
		for (int i = 0; i < c; i++) {
			if (mov[i] == 'W') {
				if (dir == 1) { //direita
					if (p_y + 1 < m) {
						if (str[p_x][p_y+1] == '#') continue;
						else if (str[p_x][p_y+1] == '*') {
							str[p_x][p_y+1] = ' ';
							p++;
						}
						p_y++;
					}
				} else if (dir == 2){
					if (p_y -1 > -1) {
						if (str[p_x][p_y-1] == '#') continue;
						else if (str[p_x][p_y-1] == '*') {
							str[p_x][p_y-1] = ' ';
							p++;
						}
						p_y--;
					}
				} else if (dir == 3){
					if (p_x +1 < n) {
						if (str[p_x+1][p_y] == '#') continue;
						else if (str[p_x+1][p_y] == '*') {
							str[p_x+1][p_y] = ' ';
							p++;
						}
						p_x++;
					}
				} else {
					if (p_x -1 > -1) {
						if (str[p_x-1][p_y] == '#') continue;
						else if (str[p_x-1][p_y] == '*') {
							str[p_x-1][p_y] = ' ';
							p++;
						}
						p_x--;
					}
				}
			} else if (mov[i] == 'D') {
				dir = 3;
			} else if (mov[i] == 'R') {
				dir = 1;
			} else if (mov[i] == 'U') {
				dir = 4;
			} else {
				dir = 2;
			}
		}
		cout << p << endl;
	}


    return 0;
}