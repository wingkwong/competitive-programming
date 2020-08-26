/*
Creating Strings I
https://cses.fi/problemset/task/1622
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;

int main()  
{ 
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
    // #endif
    FAST_INP;
    string s;
    cin >> s;
    sort(s.begin(),s.end());
    vector<string> ans;
    // use STL
    do{
    	ans.emplace_back(s);
	}while(next_permutation(s.begin(),s.end()));
    cout << ans.size() << endl;
    for(string ss:ans) cout << ss << endl;
    return 0;
} 
