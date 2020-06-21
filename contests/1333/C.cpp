/*
Codeforces Round #632 (Div. 2) - C. Eugene and an array
https://codeforces.com/contest/1333/problem/C
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
	long long n,a,last=0,sum=0,ans=0;
	map<long long, long long> m;
    cin >> n;
    m[0]=0;
    for(int i=1;i<=n;i++){
        cin >> a;
        sum+=a;
        if(m.count(sum)) last=max(last,m[sum]+1);
		m[sum]=i;
		ans+=i-last;
    }
    cout << ans << "\n";
    return 0;
} 
