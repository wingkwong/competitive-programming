/*
Volume 2 - 1197. Lonesome Knight
https://acm.timus.ru/problem.aspx?space=1&num=1197
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;

int main()  
{ 
    FAST_INP;
    ll n;
    string s;
    cin >> n;
    int b[8][8];
    function<int(int, int)> solve = [&](int x, int y){
    	int ans=0;
		if(x-2>=1&&y+1<=8) ans++;
		if(x-1>=1&&y+2<=8) ans++;
		if(x+1<=8&&y+2<=8) ans++;
		if(x+2<=8&&y+1<=8) ans++;
		if(x+1<=8&&y-2>=1) ans++;
		if(x+2<=8&&y-1>=1) ans++;
		if(x-1>=1&&y-2>=1) ans++;
		if(x-2>=1&&y-1>=1) ans++;
		return ans;
	};
    while(n--){
    	cin >> s;
    	cout << solve(s[0]-'a'+1, s[1]-'0') << endl;
	}
    return 0;
} 
