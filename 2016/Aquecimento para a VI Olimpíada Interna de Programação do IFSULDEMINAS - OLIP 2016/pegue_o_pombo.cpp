#include <bits/stdc++.h>

#define digits(num) floor(log10(num) + 1)
#define first_bit_index(num) (num == 0 ? 0 : __builtin_ctz(abs(num))) // count trailing zeros (e.g: 8 1000, so ans: 4)
#define last_bit_index(num) (num == 0 ? 0 : __builtin_clz(abs(num))) // count leading zeros (e.g: 8 0x27 1000, so ans: 28)
#define check_bit(num, bit) ((num & 1 << bit) != 0)
#define num_bits(num) __builtin_popcount(num) //count 1 bits
#define get_low_bit(x) ((x)&((x)^((x)-1))) //get the lowest bit of x
#define set_bit(num, bit) num |= (1 << bit);
#define reset_bit(num, bit) num &= ~(1 << bit);
#define flip_bit(num, bit) num ^= (1 << bit);
#define fi first
#define se second
#define mp make_pair
#define IOS ios_base::sync_with_stdio(0); 
#define therms(type, func) type, vector<type>, func //usefull with priority queues
#define in(a,b) ( (b).find(a) != (b).end())
#define EPS 1e-9
#define INF 1000000000
#define DIM 5
#define MOD 100000009
#define is_pow2(num) (int)(num && !(num & (num - 1)))
#define cls(arr) memset(arr, 0, sizeof arr);

using namespace std;

typedef struct t { int a; bool operator<(const t &cpy) const { return a < cpy.a; } } t; //usefull with sort and sets
typedef struct cmp { bool operator()(const int& a, const int& b) const { return a > b; } } cmp; //usefull with priority queues

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

template<typename T> void swap(T *f, T *s) { *f = *f ^ *s; *s = *f ^ *s; *f = *f ^ *s; }
template<typename F,typename S> ostream& operator<<(ostream &s, pair<F,S> t) { return s<<"("<<t.fi<<","<<t.se<<")"; } //print pair
template<typename T> ostream& operator<<(ostream &s, vector<T> t){ //print vector
    for(int i = 0, sz = t.size(); i < sz; i++) s << t[i] <<" ";return s; }

int **arr = new int*[1000];
int dig;

void fill(int ini, int lado, int n)
{
    if(!n) return;
    int c, l;

    for(c = ini; c < ini+lado; c++)
        arr[ini][c] = n--;

    for(l = ini + 1; l < ini + lado; l++)
        arr[l][c-1] = n--;

    for(c = c - 2; c >= ini; c--)
        arr[l-1][c] = n--;

    for(l = l - 2; l > ini; l--)
        arr[l][c+1] = n--;

    fill(ini+1, lado-2, n);
}

int main()
{
    IOS
    int n, a;
    for (int i = 0 ; i < 1000 ; i++)
        arr[i] = new int[1000];
    
    while(cin >> n >> a) {
        dig = digits(n);
        if(a*3 > n){ cout << "Raios! Raios Duplos! Raios Triplos!\n"; continue;}

        int sqrt_n = sqrt(n);

        int l = 0, c = 0, x = 0, y = 0, z = 0, w = 0;

        fill(0, sqrt_n, n);

        for(int i = 0; i < sqrt_n; i++) {
            for(int j = 0; j < sqrt_n; j++) {
                if(arr[i][j] == a*2){ for(int i = 1; i < dig; i++) cout << " ";cout << "*"; }
                else if(arr[i][j] == a*3){ for(int i = 1; i < dig; i++) cout << " ";cout << "!"; }
                else cout << setw(dig) << arr[i][j];
                if(i != sqrt_n-1 || j != sqrt_n-1) cout << " ";
            }
            cout << endl;
        }
    }

    
    return 0;
}
