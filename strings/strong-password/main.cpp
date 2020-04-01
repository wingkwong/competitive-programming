#include <bits/stdc++.h>
using namespace std; 

int n,x,l,d,lc,uc,sc;
char c;

int main()  
{ 
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    x=l=d=lc=uc=sc=0;
    if(n>=6) l=1;
    for(int i=0;i<n;i++){
        cin >> c;
        if(isdigit(c)) d=1;
        else if(islower(c)) lc=1;
        else if(isupper(c)) uc=1;
        else if(c=='!'||c=='@'||c=='#'||c=='$'||c=='%'||c=='^'||c=='&'||c=='*'||c=='('||c==')'||c=='-'||c=='+') sc=1;
    }

    if(!d)++x;
    if(!lc)++x;
    if(!uc)++x;
    if(!sc)++x;

    // cout << l << " " << d << " " << lc << " " << uc << " " << sc << " " << x << "\n";

    // 3
    // Ab1
    // 0 1 1 1 0 1

    // 11
    // #HackerRank
    // 1 0 1 1 1 1

    // 8
    // zC9!Xx56
    // 1 1 1 1 1 0
    
    if(!l) cout << max(x, 6-n);
    else  cout << x;
        
    return 0; 
} 