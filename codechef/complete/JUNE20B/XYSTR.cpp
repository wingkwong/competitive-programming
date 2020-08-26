/*
CodeChef June Challenge 2020 Division 2 - Chef and String
https://www.codechef.com/JUNE20B/problems/XYSTR
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
	int t;
	string s;
	cin >> t;
	while(t--){
		cin >> s;
		int ans=0;
		// traverse each person starting from the second person
		for(int i=1;i<s.size();i++){
			if(
				(s[i]=='x'&&s[i-1]=='y') || // yx can be a pair
				(s[i]=='y'&&s[i-1]=='x') 	// xy can be a pair
			) {
				ans++;
				// since they are paired, increase 1 to avoid checking again 
				i++; 
			}
		}
		cout << ans << "\n";
	}
    return 0;
} 
