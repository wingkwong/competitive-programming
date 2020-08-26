/*
Codeforces Round #642 (Div. 3) - C. Board Moves
https://codeforces.com/contest/1353/problem/C
*/
#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int t,n; 
    cin >> t;
    while(t--){
    	cin >> n;
    	long long ans=0;
    	// the best way is to put it in the center ( (n-1)/2, (n-1)/2 )
    	// we can get 8 cells with distance 1, 16 cells with distance 2, 24 cells with distance 3 ...
    	// hence, we can i*8i where i starts from 1 ... (n-1)/2
    	// calculate the sum, that would be the ans
    	for(int i=1;i<=(n-1)/2;i++){
    		ans += 1LL*i*8*i;
		}
    	cout << ans << "\n";
	}
    return 0;
} 
