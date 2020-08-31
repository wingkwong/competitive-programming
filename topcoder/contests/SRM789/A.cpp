/*
TopCoder - SRM 789 - A. TapeMeasure
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
#define OUTH(x) cout << x << " "
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


class TapeMeasure {
	public:
	vector <string> draw(int leftMark, int rightMark)
	{
	    FAST_INP;
	    vector <string> ans;
	    string s1(2005,'#');
	    string s2(1,'#'),s3(1,'#'),s4(1,'#'),s5(1,'0'), s5space(19,' ');
	    s5+=s5space;
		FOR(i,1,2005) {
			s2+=i&1?" ":"#";
			s3+=i%10?" ":"#";
			s4+=i%20?" ":"#";
			if(i%10==0){
				string n = to_string(i);
				s5+=n;
				string space(19-(n.size()-1), ' ');
				s5+=space;
			}
		}
		int l = leftMark*2, r = rightMark*2+1;
//		OUT(s1.substr(l,r-l));
//		OUT(s2.substr(l,r-l));
//		OUT(s3.substr(l,r-l));
//		OUT(s4.substr(l,r-l));
//		OUT(s5.substr(l,r-l));
	    ans.pb(s1.substr(l,r-l));
	    ans.pb(s2.substr(l,r-l));
	    ans.pb(s3.substr(l,r-l));
	    ans.pb(s4.substr(l,r-l));
	    ans.pb(s5.substr(l,r-l));
	    return ans;
	}
};


//int main(){
//	TapeMeasure s;
//	s.draw(981, 990);
//	return 0;
//}
