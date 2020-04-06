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

// O(N^2) Approach - TLE
// ---------------------------------------------
// int lis(vi a, int n){
//     vi l(n);
//     vi s(n); 
//     int max=0;

//     l[0]=1;
//     FOR(i, 1, n){
//         l[i] = 1;
//         REP(j,i){
//             if(a[j] < a[i]){
//                 if(l[j]+1>l[i]){
//                     l[i]=l[j]+1;
//                     s[i]=j;
//                     if(l[i]>max) max=l[i];
//                 }
//             }
//         }
//     }
//     return max;
// }

// O(NlogN) Binary Search Approach - TLE
// -----------------------------------
// int bs(vi &v, int max, int r, int k){
//     while(r-1>1){
//         int m=1+(r-1)/2;
//         if(v[m]>=k) r=m;
//         else max=m;
//     } 
//     return r;
// }

// int lis(vi a, int n){
//     vi t(n);
//     t[0] = a[0];
//     int max=1;

//     FOR(i,1,n){
//         // case 1
//         // If a[i] is smallest among all end 
//         // candidates of active lists, we will start 
//         // new active list of length 1.
//         if(a[i]<t[0]) t[0]=a[i];
//         // case 2
//         // If a[i] is largest among all end candidates of 
//         // active lists, we will clone the largest active 
//         // list, and extend it by a[i].
//         else if(a[i]>t[max-1]) t[max++]=a[i];
//         // case 3
//         //   If a[i] is in between, we will find a list with 
//         //   largest end element that is smaller than a[i]. 
//         //   Clone and extend this list by a[i]. We will discard all
//         //   other lists of same length as that of this modified list.
//         else t[bs(t,-1,max-1,a[i])]=a[i];
//     }
//     return max;
// }

int main()  
{ 
    FAST_INP;
    int n;

    cin >> n;
    vi a(n);
    vi v;

    REP(i,n){
        vi::iterator it;

        cin >> a[i];
        if(i==0) v.push_back(a[i]);
        else {
            it=lower_bound(v.begin(),v.end(),a[i]);
            int k=it-v.begin();
            if(k==v.size()) v.push_back(a[i]);
            else v[k]=a[i];
        }
    }
    cout << v.size();
    return 0; 
} 


// 2 4 3 7 4 5

// i:0
// ----
// v=[2]

// i:1
// ----
// k=1
// v=[2,4]

// i:2 
// ----
// k=1
// v=[2,3]

// i:3
// ----
// k=2
// v=[2,3,7]

// i:4
// ----
// k=2
// v=[2,3,4]

// i:5
// ----
// k=3
// v=[2,3,4,5]
