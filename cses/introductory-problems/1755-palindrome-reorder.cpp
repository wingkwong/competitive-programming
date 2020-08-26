/*
Palindrome Reorder
https://cses.fi/problemset/task/1755/

Given a string, your task is to reorder its letters in such a way that it becomes a palindrome (i.e., it reads the same forwards and backwards).

Input

The only input line has a string of length n consisting of characters A–Z.

Output

Print a palindrome consisting of the characters of the original string. You may print any valid solution. If there are no solutions, print "NO SOLUTION".

Constraints
1≤n≤106
Example

Input:
AAAACACBA

Output:
AACABACAA
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
    int cnt[26]={}, odd=0;
    for(char c:s) cnt[c-'A']++;
    for(int i=0;i<26;i++) {
        if(cnt[i]&1) odd++;
    }
    if(odd>1){
        cout << "NO SOLUTION" << endl;
        return 0;
    } 

    // Example: 
    // AAAACACBA
    // AAAC(first) B(middle) CAAA(last)

    string first="", middle="", last="";
    for(int i=0;i<26;i++){
        if((cnt[i]&1)^1){
            for(int j=0;j<cnt[i]/2;j++){
                first+=(char)('A'+i);
            }
        }
    }
    for(int i=0;i<26;i++){
        if(cnt[i]&1){
            for(int j=0;j<cnt[i];j++){
                middle+=(char)('A'+i);
            }
        }
    }
    last=first;
    reverse(last.begin(),last.end());
    cout << first+middle+last << endl;
    return 0;
} 