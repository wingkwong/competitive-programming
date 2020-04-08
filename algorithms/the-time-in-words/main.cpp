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

int h,m;
char nums[][64] = { "zero", "one", "two", "three", "four", 
                    "five", "six", "seven", "eight", "nine", 
                    "ten", "eleven", "twelve", "thirteen", 
                    "fourteen", "fifteen", "sixteen", "seventeen", 
                    "eighteen", "nineteen", "twenty", "twenty one", 
                    "twenty two", "twenty three", "twenty four", 
                    "twenty five", "twenty six", "twenty seven", 
                    "twenty eight", "twenty nine", 
                    }; 

int main()  
{ 
    FAST_INP;
    cin >> h >> m;

    if (m == 0) 
        printf("%s o' clock\n", nums[h]); 
  
    else if (m == 1) 
        printf("one minute past %s\n", nums[h]); 
  
    else if (m == 59) 
        printf("one minute to %s\n", nums[(h % 12) + 1]); 
  
    else if (m == 15) 
        printf("quarter past %s\n", nums[h]); 
  
    else if (m == 30) 
        printf("half past %s\n", nums[h]); 
  
    else if (m == 45) 
        printf("quarter to %s\n", nums[(h % 12) + 1]); 
  
    else if (m <= 30) 
        printf("%s minutes past %s\n", nums[m], nums[h]); 
  
    else if (m > 30) 
        printf("%s minutes to %s\n", nums[60 - m], nums[(h % 12) + 1]); 
  
    return 0; 
} 