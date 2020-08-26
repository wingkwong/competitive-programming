/*
Codeforces Beta Round #2 - A. Winner
https://codeforces.com/contest/2/problem/A
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int t,m;
    string n,ans;
    cin >> t;
    int mx=INT_MIN;
    map<string,int> mp,mp2;
    string p[3000];
    int s[3000];
    for(int i=0;i<t;i++){
    	// read the input
    	cin >> p[i] >> s[i];
    	// store <person,score> to a map
    	mp[p[i]]+=s[i];
	}
	// find out the max score
	for(auto lt=mp.begin();lt!=mp.end();lt++) mx=max(lt->second,mx);
	for(int i=0;i<t;i++){
		// find out the current round score
		mp2[p[i]]+=s[i];
		// if the score is greater than the max score 
		// and this person has the max score at the end
		// then he is the first one to acheive it
		// break immediately as person p[i] is the winner
		if(mp2[p[i]]>=mx&&mp[p[i]]==mx){
			ans=p[i];
			break;
		}
	}
	cout << ans << "\n";
    return 0;
} 
