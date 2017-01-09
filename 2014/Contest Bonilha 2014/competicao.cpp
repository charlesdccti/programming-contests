#include <iostream>

using namespace std;

int main()
{
    int N, M, i, j, q;
    int p;

    while (1){
        cin >> N >> M;
        if (!N && !M)
            break;

        q = 0;
        int mat[N][M];
        for (i=0; i<N; i++)
            for (j=0; j<M; j++)
                cin >> mat[i][j];

        p = 0;
        for (i=0; i<N; i++){
            for (j=0; j<M; j++){
                if (mat[i][j] == 0){
                    p++;
                    break;
                }
            }
        }
        if (p==N)
            q++;

        p = 0;
        for (i=0; i<N; i++){
            for (j=0; j<M; j++){
                if (mat[i][j] == 1){
                    p++;
                    break;
                }
            }
        }
        if (p==N)
            q++;

        p = 0;
        for (i=0; i<M; i++){
            for (j=0; j<N; j++){
                if (mat[j][i] == 0){
                    p++;
                    break;
                }
            }
        }
        if (p==M)
            q++;

        p = 0;
        for (i=0; i<M; i++){
            for (j=0; j<N; j++){
                if (mat[j][i] == 1){
                    p++;
                    break;
                }
            }
        }
        if (p==M)
            q++;

        cout << q << endl;
    }

    return 0;
}