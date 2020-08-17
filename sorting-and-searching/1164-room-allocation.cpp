/*
Room Allocation
https://cses.fi/problemset/task/1164/

There is a large hotel, and n customers will arrive soon. Each customer wants to have a single room.

You know each customer's arrival and departure day. Two customers can stay in the same room if the departure day of the first customer is earlier than the arrival day of the second customer.

What is the minimum number of rooms that are needed to accommodate all customers? And how can the rooms be allocated?

Input

The first input line contains an integer n: the number of customers.

Then there are n lines, each of which describes one customer. Each line has two integers a and b: the arrival and departure day.

Output

Print first an integer k: the minimum number of rooms required.

After that, print a line that contains the room number of each customer in the same order as in the input. The rooms are numbered 1,2,…,k. You can print any valid solution.

Constraints
1≤n≤2⋅105
1≤a≤b≤109
Example

Input:
3
1 2
2 4
4 4

Output:
2
1 2 1
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
const ll MOD = 1000000007;

#define DEBUG fprintf(stderr, "====TESTING====\n") 
#define VALUE(x) cerr << "The value of " << #x << " is " << x << endl 
#define OUT(x) cout << x << endl 
#define debug(...) fprintf(stderr, __VA_ARGS__) 
#define READ(x) for(auto &(z):x) cin >> z;
#define FOR(a, b, c) for (int(a)=(b); (a) < (c); ++(a)) 
#define FORN(a, b, c) for (int(a)=(b); (a) <= (c); ++(a)) 
#define FORD(a, b, c) for (int(a)=(b); (a) >= (c); --(a)) 
#define FORSQ(a, b, c) for (int(a)=(b); (a) * (a) <= (c); ++(a)) 
#define FORC(a, b, c) for (char(a)=(b); (a) <= (c); ++(a)) 
#define EACH(a, b) for (auto&(a) : (b)) 
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
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
    // #endif
    
    int n; cin >> n;
    vector<pair<int,pii>> v;
    REP(i,n){
        int in,out; cin >> in >> out;
        v.pb({in,{-1,i}}), v.pb({out,{1,i}});
    }
    SORT(v);
    vi rooms, ans(n);
    int cnt=0, rn=0;
    EACH(k,v){
        int i = k.second.second;
        // cout << k.first << " " << k.second.first << " " << k.second.second << endl;
        if(k.second.first==1) rooms.pb(ans[i]);
        else if(rooms.size()==cnt) ans[i]=++rn;
        else ans[i]=rooms[cnt++];
    }
    OUT(rn);
    EACH(x, ans) cout << x << " ";
    return 0; 
} 
