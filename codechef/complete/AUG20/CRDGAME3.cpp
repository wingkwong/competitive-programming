/*
August Challenge 2020 Division 2  - Another Card Game Problem
https://www.codechef.com/AUG20B/problems/CRDGAME3
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;

int countDigits(int n){
	return n%9==0?n/9:n/9+1;
}

void solve(){
	int c,r;
	cin >> c >> r;
	if(c<10&&r<10) {
		printf("1 1\n");
		return;
	}
	int cc=countDigits(c), rr=countDigits(r);
	if(cc<rr) cout << 0 << " " << cc << "\n";
    else cout << 1 << " " << rr << "\n";
}

void solve2(){
    // 1 <= sum <= 9 => at least 1 digit
    // 10 <= sum <= 18 => at least 2 digit
    // 19 <= sum <= 27 => at least 3 digit
    // and so on
    int c,r;
    cin >> c >> r;
    // minimum number of digits required = (N+8)/9
    c=(c+8)/9, r=(r+8)/9;
    cout << (c>=r) << " " << min(c,r) << "\n";

}

int main()  
{ 
    FAST_INP;
    int t;
    cin >> t;
    while(t--){
    	solve2();
	}
    return 0;
} 