#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
int main()  
{ 
    FAST_INP;
    string s;
    cin >> s;
    int ans=1,cnt=1;
    for(int i=1;i<s.size();i++){
    	// if s[i] is same as previous character
    	// increase cnt
    	if(s[i]==s[i-1]) cnt++;
    	// if not, reset cnt
    	else cnt=1;
    	// take the max
    	ans=max(ans,cnt);
	}
	cout << ans << "\n";
    return 0;
} 
