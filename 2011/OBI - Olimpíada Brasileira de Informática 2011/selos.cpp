#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    long long n; cin >> n;
    int max = sqrt(n);

    for (int i = 2; i <= max; i++)
        if (n % i == 0 && n / i > 1)
    {
        cout << "S" << endl;
        return 0;
    }

    cout << "N" << endl;
    return 0;
}   