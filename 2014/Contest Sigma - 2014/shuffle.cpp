#include <iostream>

using namespace std;

int main()
{
	int M, K;
	int i, j, total;

	while (cin >> M >> K)
	{
		total = 0;
		int album[M];
		int playlist[K];
		int tocou[M];

		for (i=0; i<M; i++)
			tocou[i] = 0;

		for (i=0; i<M; i++)
			cin >> album[i];

		for (i=0; i<K; i++)
			cin >> playlist[i];

		for (i=0; i<K; i++){
			tocou[playlist[i]-1] = 1;
			total+=album[playlist[i]-1];

			for (j=0; j<M; j++)
				if(tocou[j]==0)
					break;

			if (j==M){
				cout << total << endl;
				break;
			}
		}

		for (i=0; i<M; i++){
			if (tocou[i] == 0){
				cout << "-1\n";
				break;
			}
		}
	}

	return 0;
}