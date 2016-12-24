#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int N, i, M, j, aux;
    int q;
    vector<int> myvector;
    vector<int> myvector_sorted;

    cin >> N;
    for (i=0; i<N; i++)
    {
        while (!myvector.empty()) myvector.pop_back();
        cin >> M;
        for (j=0; j<M; j++) {
            cin >> aux;
            myvector.push_back(aux);
        }

        myvector_sorted = myvector;
        sort(myvector_sorted.begin(), myvector_sorted.end());

        q = 0;
        for (j=0; j<M; j++) {
            if(myvector[j] == myvector_sorted[M-1-j])
                q++;
        }

        cout << q << endl;
    }


    return 0;
}