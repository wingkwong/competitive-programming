#include <bits/stdc++.h>
using namespace std; 

int cnt=1; string s;

int main()  
{ 
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    for(int i=0;i<s.size();++i)
        if(isupper(s[i])) cnt++;
    cout << cnt;
    return 0; 
} 