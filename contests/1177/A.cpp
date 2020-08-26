/*
A. Digits Sequence (Easy Edition)
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Let's write all the positive integer numbers one after another from 1 without any delimiters (i.e. as a single string). It will be the infinite sequence starting with 123456789101112131415161718192021222324252627282930313233343536...

Your task is to print the 𝑘-th digit of this sequence.

Input
The first and only line contains integer 𝑘 (1≤𝑘≤10000) — the position to process (1-based index).

Output
Print the 𝑘-th digit of the resulting infinite sequence.

Examples

input
7
output
7
input
21
output
5
*/

#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll; 
typedef pair<string, string> pss; 
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef vector<pii> vii; 
typedef vector<ll> vl; 
typedef vector<vl> vvl; 

double EPS=1e-9; 
int INF=1000000005; 
long long INFF=1000000000000000005ll; 
double PI=acos(-1); 
int dirx[8]={ -1, 0, 0, 1, -1, -1, 1, 1 }; 
int diry[8]={ 0, 1, -1, 0, -1, 1, -1, 1 }; 

#define DEBUG fprintf(stderr, "====TESTING====\n") 
#define VALUE(x) cerr << "The value of " << #x << " is " << x << endl 
#define debug(...) fprintf(stderr, __VA_ARGS__) 
#define FOR(a, b, c) for (int(a)=(b); (a) < (c); ++(a)) 
#define FORN(a, b, c) for (int(a)=(b); (a) <= (c); ++(a)) 
#define FORD(a, b, c) for (int(a)=(b); (a) >= (c); --(a)) 
#define FORSQ(a, b, c) for (int(a)=(b); (a) * (a) <= (c); ++(a)) 
#define FORC(a, b, c) for (char(a)=(b); (a) <= (c); ++(a)) 
#define FOREACH(a, b) for (auto&(a) : (b)) 
#define REP(i, n) FOR(i, 0, n) 
#define REPN(i, n) FORN(i, 1, n) 
#define MAX(a, b) a=max(a, b) 
#define MIN(a, b) a=min(a, b) 
#define SQR(x) ((ll)(x) * (x)) 
#define RESET(a, b) memset(a, b, sizeof(a)) 
#define fi first 
#define se second 
#define mp make_pair 
#define pb push_back 
#define ALL(v) v.begin(), v.end() 
#define ALLA(arr, sz) arr, arr + sz 
#define SIZE(v) (int)v.size() 
#define SORT(v) sort(ALL(v)) 
#define REVERSE(v) reverse(ALL(v)) 
#define SORTA(arr, sz) sort(ALLA(arr, sz)) 
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz)) 
#define PERMUTE next_permutation 
#define TC(t) while (t--) 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)


int main()  
{ 
    FAST_INP;
    ll n;
    cin >> n;
    // 1~9: 1*9=9 in total
    // 10~99: 2*90=180 in total
    // 100~999: 3*900=2700 in total

    // Example: n=250
    int digits=1;
    int base=9;
    while(n-base*digits>0) {
        n -= base*digits;
        base *= 10;
        digits++;
    }
    // n=61 (250-9-180)
    // digits=3
    // We need to get the 61th number starting from 100
    // idx=0
    ll idx = (n-1)%digits;
    // offset=20
    ll offset = (n-1)/digits;
    // k=100 (10^(3-1))
    ll k = pow(10,digits-1);
    // 100+20 -> 120 -> 1
    cout << to_string(k+offset)[idx] - '0' << "\n";
    return 0;
} 