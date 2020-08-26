/*
AtCoder Beginner Contest 176 - D - Wizard in Maze
https://atcoder.jp/contests/abc176/tasks/abc176_d
*/

#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll; 
typedef pair<string, string> pss; 
typedef vector<int> vi; 
typedef vector<bool> vb; 
typedef vector<vi> vvi;  
typedef vector<vb> vvb; 
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
#define OUTH(x) cout << x << " " 
#define debug(...) fprintf(stderr, __VA_ARGS__) 
#define READ(x) for(auto &(z):x) cin >> z;
#define FOR(a, b, c) for (int(a)=(b); (a)<(c); ++(a)) 
#define FORN(a, b, c) for (int(a)=(b); (a) <= (c); ++(a)) 
#define FORD(a, b, c) for (int(a)=(b); (a)>=(c); --(a)) 
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


void solve() {
    int h, w, cH, cW, dH, dW;
    char ch;
    cin >> h >> w >> cH >> cW >> dH >> dW;
    cH--, cW--, dH--, dW--;
    vvb g(h, vb(w)), vis(h, vb(w));
    // set the path as true, wall as false
    REP(r, h) REP(c, w) {
        cin >> ch;
        g[r][c]=(ch=='.');
    }
    // bfs
    set<tuple<int, int, int>> q; // {cnt, row, col}
    q.emplace(0, cH, cW);
    while((int)q.size()) {
        auto [cnt, r, c]=*q.begin();
        q.erase(q.begin());
        vis[r][c] = true;
        // if destination has been reached, return the answer
        if(r==dH && c==dW) {
            OUT(cnt);
            return;
        }
        // the magician (displayed as o) can perform move A (displayed as a) or move B (displayed as b)
        // bbbbb
        // bbabb
        // baoab
        // bbabb
        // bbbbb
        FOR(row, -2, 3) {
            FOR(col, -2, 3) {
                // skip if it is in current position
                if(!row&&!col) continue;
                int rr=r+row, cc=c+col;
                if(rr<0||rr>=h||cc<0||cc>=w||vis[rr][cc]||!g[rr][cc]) continue;
                // if the next move is Move A (left, right, top, down), just pass the cnt
                if((abs(row)==1&&!abs(col))||(abs(col)==1&&!abs(row))) q.emplace(cnt, rr, cc);
                // if not, the next move is Move B, so increase cnt by 1
                else q.emplace(cnt+1, rr, cc);
            }
        }
    }
    // no such path to reach destination
    OUT(-1);
}

int main()  
{ 
    FAST_INP;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt","w", stdout);
    #endif
    
    // int tc; cin >> tc;
    // TC(tc) solve();
    solve();

    return 0; 
}