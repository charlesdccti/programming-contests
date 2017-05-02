#include <bits/stdc++.h>

using namespace std;

void merge(int *v, int s, int m, int e, int &iix)
{
    int sz = e - s + 1;
    int *t = new int[sz+1];
    int i = s, j = m + 1;

    if (t != NULL)
    {
        for (int c = 0; c < sz; c++) {
            if (j <= e && i <= m) {
                if (v[i] < v[j]) t[c] = v[i++];
                else {
                    iix += m - i + 1;
                    t[c] = v[j++];
                }
            } else {
                if (j > e) t[c] = v[i++];
                else t[c] = v[j++];
            }
        }
    }

    for(int i = 0, j = s; i < sz; i++, j++) v[j] = t[i];

    delete []t;
}

void mergeSort(int *v, int s, int e, int &iix)
{
    if (s < e) {
        mergeSort(v, s, (s+e)/2, iix);
        mergeSort(v, (s+e)/2 + 1, e, iix);
        merge(v, s, (s+e)/2, e, iix);
    }
}

int inversionIndex(int *v, int sz)
{
    int iix = 0;
    mergeSort(v, 0, sz - 1, iix);
    return iix;
}

int main()
{
    int v[100000], n;

    cin >> n;
    for (int i = 0; i < n; i++) cin >> v[i];
    cout << inversionIndex(v, n) << endl;

    return 0;
}
