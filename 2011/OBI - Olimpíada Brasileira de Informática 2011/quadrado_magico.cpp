#include <bits/stdc++.h>

using namespace std;
 
int main()
{
    int N, sumDP = 0, sumDS = 0, curr;
    cin >> N;
    int max = N * N;
    int matrix[N][N];
    bool values[max];
    memset(values, false, sizeof values);

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++) {
            cin >> matrix[i][j];
            curr = matrix[i][j];
            if(curr > max || values[curr - 1]) {
                cout << '0' << endl; return 0;
            } else values[curr - 1] = true;
            if(i == j) sumDP += curr;
            if(i + j == N - 1) sumDS += curr;
        }

    if(sumDS != sumDP) {
        cout << '0' << endl; return 0;
    }

    int line_sum, column_sum;
    for(int i = 0; i < N; i++) {
        line_sum = column_sum = 0;
        for(int j = 0; j < N; j++) {
            line_sum += matrix[i][j];
            column_sum += matrix[j][i];
        }
        if(line_sum != sumDS || column_sum != sumDS) {
            cout << '0' << endl; return 0;
        }
    }

    cout << sumDS << endl;

    return 0;
}
