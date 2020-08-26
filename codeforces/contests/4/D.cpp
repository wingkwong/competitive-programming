/*
Codeforces Beta Round #4 (Div. 2 Only) - D. Mysterious Present
https://codeforces.com/problemset/problem/4/D
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)


// Wrong answer on test 16
// should use DP ...
int main()  
{ 
    FAST_INP;
    int n,w,h,ww,hh;
    cin >> n >> w >> h;
    vector<pair<pair<int,int>, int>> vp;
    for(int i=0;i<n;i++){
    	cin >> ww >> hh;
    	pair<int,int> p = make_pair(ww,hh);
    	vp.push_back({p,i});
    	
	}
	sort(vp.begin(),vp.end());
	int ans=0;
	vector<int> ans2;
	for(int i=0;i<n;i++){
		int f=vp[i].first.first;
		int s=vp[i].first.second;
//		cout << "w: " << w << " h: " << h << endl;
//		cout << "f: " << f << " s: " << s << endl;
		if(w<f&&h<s){
			ans++;
			ans2.push_back(vp[i].second+1);
			w=f;
			h=s;
		} else {
			continue;
		}
	}
	
	if(ans){
		cout << ans << "\n";
		for(int a:ans2) cout << a << " ";
	} else {
		cout << 0;
	}
	cout << "\n";
	
//	for(int i=0;i<vp.size();i++){
//		cout << vp[i].first.first << " " << vp[i].first.second  << endl;
//	}
	
    return 0;
} 
