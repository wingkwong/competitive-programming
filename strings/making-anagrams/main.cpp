#include <bits/stdc++.h>
using namespace std; 

string s1,s2;
int r=0;

int main()  
{ 
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s1 >> s2;
    for(int c='a';c<='z';++c){
        r+=abs(count(s1.begin(),s1.end(),c) - count(s2.begin(),s2.end(),c));
    }
    cout << r;
    return 0; 
}

// ------------------------------
// s1: aaaaaabc
// s2: aaaaabbc
//  r: aaaaabc
// ------------------------------
// s1               | a:6 b:1 c:1
// s2               | a:5 b:2 c:1
// expected         | a:5 b:1 c:1
// to-be-deleted    | a:1 b:1 c:0
// ------------------------------