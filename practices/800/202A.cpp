/*
Codeforces Round #127 (Div. 2) - A. LLPS
https://codeforces.com/contest/1399/problem/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;

bool isPalindrome(string s){
    string ss = s;
    reverse(ss.begin(),ss.end());
    return s==ss;
}

int main()  
{ 
    FAST_INP;
    string s,ss,ans;
    cin >> s;
    int n = s.size();
    ans=s[0];
    for(int mask=0;mask<(1<<n);mask++){
        ss="";
        for(int i=0;i<n;i++){
            if(mask&(1<<i)){
                ss+=s[i];
                if(isPalindrome(ss)){
                    if(ss>ans){
                        ans=ss;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
} 
