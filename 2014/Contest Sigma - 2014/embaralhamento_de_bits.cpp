#include <bits/stdc++.h>

using namespace std;

int main()
{
	unsigned int N, K, A, B, a, b, ma, mi;

	while (cin >> N >> K && N)
	{
		ma = mi = N;

		while (K--)
		{
			cin >> A >> B;

			a = 0 | (N & (1 << A));
			b = 0 | (N & (1 << B));

			if ((a == 0 && b != 0) || (a != 0 && b == 0)) {
				if (a != 0) { // a = 1 | b = 0
					N &= ~(1 << A);
					N |= (1 << B);
				} else { // a = 0 | b = 1
					N &= ~(1 << B);
					N |= (1 << A);
				}
			}

			ma = max(ma, N);
			mi = min(mi, N);
		}

		cout << N << " " << ma << " " << mi << endl;
	}

	return 0;
}