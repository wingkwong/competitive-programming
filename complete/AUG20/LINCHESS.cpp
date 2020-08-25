/*
August Challenge 2020 Division 2  - Chef and Linear Chess
https://www.codechef.com/AUG20B/problems/LINCHESS
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;

int main()  
{ 
    FAST_INP;
    int t,n,k;
    cin >> t;
    while(t--){
    	cin >> n >> k;
    	vector<int> p(n);
    	for(auto &x:p) cin >> x;
    	int ans=-1, t=1e9+5;
    	for(int i=0;i<n;i++){
            // find a player who can capture Chef's pawn in the smallest number of moves 
            // or determine that no player can capture his pawn
    		if(k%p[i]) continue;
    		if((k/p[i])<t){
    			t=k/p[i];
    			ans=p[i];
			}
		}
		cout << ans << endl;
	}
    return 0;
} 