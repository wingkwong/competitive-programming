/*
August Challenge 2020 Division 2  - Chef Wars - Return of the Jedi
https://www.codechef.com/AUG20B/problems/CHEFWARS
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;

void solve(){
	int h,p;
	cin >> h >> p;
	ll sum=0;
    // just simulate it
	while(p){
		sum+=p;
		if(sum>=h){
			cout << 1 << endl;
			return;
		}
		p>>=1;
	}
	cout << 0 << endl;
}

void solve2(){
    int h, p;
    cin >> h >> p;
    while(h&&p){
        h-=p;
        p>>1;
    }
    cout << (h<=0?1:0) << endl;
}

int main()  
{ 
    FAST_INP;
    int t;
    cin >> t;
    while(t--){
    	solve();
	}
    return 0;
} 