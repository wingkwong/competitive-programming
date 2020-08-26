/*
Codeforces Round #662 (Div. 2) - B. Applejack and Storages
https://codeforces.com/contest/1393/problem/B
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;

int main()  
{ 
    FAST_INP;
    int n,q,cnt2=0,cnt4=0;
    cin >> n;
    vector<int> a(n);
    unordered_map<int,int> m;
    for(int &x:a) {
    	cin >> x;
    	// cnt2: 2 pairs of planks of the same length (rectangle)
    	// cnt4: 4 pairs of planks of the same length (square)
    	cnt2-=m[x]/2, cnt4-=m[x]/4;
    	m[x]++;
    	cnt2+=m[x]/2, cnt4+=m[x]/4;
	}
	cin >> q;
    for(int i=0;i<q;i++){
    	char c;
		int x;
    	cin >> c >> x;
    	cnt2-=m[x]/2, cnt4-=m[x]/4;
    	if(c=='+') m[x]++;
    	else m[x]--;
    	cnt2+=m[x]/2, cnt4+=m[x]/4;
    	if(cnt4>=1&&cnt2>=4) cout << "YES\n";
    	else cout << "NO\n";
	}
    return 0;
} 

//111112
//1111122
//11111221
//1111122
//11111222
//1111222
//11112222

