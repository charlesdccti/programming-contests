#include <bits/stdc++.h>

#define digits(num) (num == 0 ? 0 : (int)((log(abs(num))/log(10))+1))
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
#define pb push_back
#define IOS ios_base::sync_with_stdio(0); 
#define therms(type, func) type, vector<type>, func //usefull with priority queues
#define in(a,b) ( (b).find(a) != (b).end())
#define EPS 1e-9
#define INF 10000000
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

int sumOfDivisors(int n/*, set<int> &f*/)
{
    int s = 0;
    int sqrt_n = sqrt(n);

    for(int i = 2; i <= sqrt_n; i++)
        if(n%i == 0) {
            //f.insert(i);
            //f.insert(n/i);
            s += (i + n/i);
        }

    if(n == sqrt_n * sqrt_n) s -= sqrt_n;

    return s + 1; 
}

int main()
{
    IOS

    int n, m, sn, sm;
    set<int> setn, setm;
    while(cin >> n >> m && n) {
        //setn.clear();
        //setm.clear();
        sn = sumOfDivisors(n/*, setn*/);
        sm = sumOfDivisors(m/*, setm*/);
        if(m%sn == 0 && n%sm == 0) {
            cout <<"Friends and lovers <3" << endl;
        } else if(sm == sn) {
            cout <<"Almost lovers!" << endl;
        } else if(m%sn == 0) {
            cout << m << " friendzoned " << n << "!\n";
        } else if(n%sm == 0) {
            cout << n << " friendzoned " << m << "!\n";
        } else{
            cout <<"No connection.\n";
        }
    }
    
    return 0;
}
