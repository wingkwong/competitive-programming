/*
F - Three Variables Game
https://atcoder.jp/contests/abc166/tasks/abc166_f
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
int main()  
{ 
    FAST_INP;
    int n; string ss;
    vector<char> ans;
    vector<string> s;
    unordered_map<char,int> m;
    cin >> n >> m['A'] >> m['B'] >> m['C'];
    for(int i=0;i<n;i++) {
        cin >> ss;
        s.push_back(ss);
    }
    for(int i=0;i<n;i++){
        char x=s[i][0],y=s[i][1];
        if(m[x]>m[y]) {
            m[y]++; m[x]--;
            ans.push_back(y);
        } else if(i+1<n&&m[x]==m[y]){
            // AB  // BA
            // AC  // AC
            if(s[i+1][0]==x||s[i+1][1]==x){
                m[x]++;
                m[y]--;
                ans.push_back(x);
            } else if(s[i+1][0]==y||s[i+1][1]==y) {
                m[y]++;
                m[x]--;
                ans.push_back(y);
            }
        }  else {
            m[x]++; m[y]--;
            ans.push_back(x);
        }

        if(m[x]<0||m[y]<0) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    for(char ch:ans) cout << ch << "\n";
    // cout << m['A'] << " " <<  m['B'] << " "  << m['C'] << endl;
    return 0;
} 
