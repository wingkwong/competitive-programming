/*
Educational Codeforces Round 87 (Rated for Div. 2) - B - Ternary String
https://codeforces.com/contest/1354/problem/B
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

string helper(string s, string t) {
    vector<int> hist(128, 0);
    for (char c:t) hist[c]++;
    int cnt=t.size(),begin=0,end=0,minStart=0,minLen=INT_MAX;
    // move end pointer to locate a valid window
    while (end<s.size()){
        // if the char s[end] exists in the map, decrease the counter   
        // decrease hist[s[end]], if char doesn't exist, hist[s[end]] will be negative
        if (--hist[s[end++]]>=0) cnt--;
        // cnt==0 means the window is valid
        while (cnt==0){
            // move start pointer to locate a smaller window
            if (end-begin<minLen){
                minLen=end-begin;
                minStart=begin;
            }
            // when char exists in t, increase the counter
            if (++hist[s[begin++]]>0) cnt++;
        }
    }
    return minLen<INT_MAX?s.substr(minStart, minLen) : "";
}

int main()  
{ 
    FAST_INP;
    int t;
    string s;
    cin >> t;
    while(t--){
        cin >> s;
        string ans = helper(s,"123");
        cout << ans.size() << "\n";
    }
    return 0;
} 
