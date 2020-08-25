/*
August Challenge 2020 Division 2  - Smallest KMP
https://www.codechef.com/AUG20B/problems/SKMP
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;

void solve(){
    string s, p;
    cin >> s >> p;
    vector<int> cnt(26,0);
    for(char c:s) cnt[c-'a']++;
    for(char c:p) cnt[c-'a']--;
    int ok=1, n=p.size();
    // find all the extra characters in S which are not contributing in P 
    for(int i=1;i<n;i++) {
        if(p[i]==p[i-1]) continue;
        if(p[i]<p[i-1]) ok=0;
        break;
    }
    int pos = p[0]-'a'+ok;
    for(int i=0;i<pos;i++){
        while(cnt[i]){
            cout << (char)('a'+i);
            cnt[i]--;
        }
    }
    cout << p;
    // else we need to find all the extra characters in S which are not contributing in P
    // and append them at the start of P if the character is smaller then P0 else append them at the end of P
    for(int i=pos;i<26;i++){
        while(cnt[i]){
            cout << (char)('a'+i);
            cnt[i]--;
        }
    }
    cout << "\n";
}

int main()  
{ 
    FAST_INP;
    int t;
    cin >> t;
    while(t--){
    	solve();
	}
    return 0;
} 

// S: bab ; P: ba -> T: abb
// S: baa ; P: ab -> T: aab