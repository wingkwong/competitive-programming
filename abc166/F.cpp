/*
F - Three Variables Game
https://atcoder.jp/contests/abc166/tasks/abc166_f

*******UNSOLVED*******

Failed cases:
killer_01.txt		2 ms	3564 KB
killer_02.txt		2 ms	3484 KB
killer_03.txt		2 ms	3608 KB
killer_04.txt		2 ms	3484 KB
killer_05.txt		2 ms	3596 KB
killer_07.txt		2 ms	3516 KB
killer_08.txt		2 ms	3608 KB
killer_09.txt		2 ms	3496 KB
killer_10.txt		2 ms	3552 KB
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
int main()  
{ 
    FAST_INP;
    int n; 
    vector<char> ans;
    unordered_map<char,int> m;
    string s;
    cin >> n >> m['A'] >> m['B'] >> m['C'];
    if(n==0)
    while(n--){
        cin >> s;
        char x=s[0],y=s[1];
        if(m[x]>m[y]) {
            m[y]++; m[x]--;
            ans.push_back(y);
        } else {
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
    return 0;
} 
