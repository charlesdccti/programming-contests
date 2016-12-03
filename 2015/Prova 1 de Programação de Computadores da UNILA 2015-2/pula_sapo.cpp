#include <cstdio>
#include <cmath>

int main()
{
	int P, N, ant, atu, gameover;

	while (scanf("%d %d", &P, &N)!=EOF)
	{
		scanf("%d", &ant);
		gameover = 0;
		for (int i=1; i<N; i++){
			scanf("%d", &atu);
			if (std::abs(atu-ant)>P)
				gameover = 1;
			ant = atu;
		}
		if (gameover) printf("GAME OVER\n");
		else printf("YOU WIN\n");
	}

	return 0;
}