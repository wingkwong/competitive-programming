/*
Orac and LCM
https://codeforces.com/contest/1350/problem/C
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

long long gcd(long long a, long long b) {
	return b?gcd(b,a%b):a;
}
long long lcm(long long a, long long b) {
	return a*b/gcd(a,b);
}

int main()  
{ 
    FAST_INP;
    long long n,a[200005],s[200005],ans=0; 
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    //gcd1=gcd(lcm(a1,a2),lcm(a1,a3),lcm(a1,a4),...lcm(a1,an))
    //gcd1=lcm(a1,gcd(a2,a3,...,an))
    //gcd=gcd(gcd1,gcd2,gcd3...,gcdn)
    for(int i=n;i>=1;i--) s[i]=gcd(s[i+1],a[i]);
    for(int i=1;i<=n;i++) ans=gcd(ans,lcm(a[i],s[i+1]));
    cout << ans << "\n";
    return 0;
} 

// -------------------------------
// Wrong answer on test 5
// -------------------------------
// 100000
// 159538 79769 159538 79769 159538 159538 79769 79769 79769 79769 79769 159538 79769 79769 79769 159538 79769 159538 159538 159538 79769 79769 159538 79769 79769 159538 159538 79769 159538 159538 159538 159538 159538 79769 159538 159538 79769 159538 79769 79769 79769 159538 159538 159538 79769 159538 79769 159538 79769 159538 159538 159538 79769 159538 159538 159538 159538 159538 159538 159538 159538 79769 159538 159538 79769 159538 159538 79769 79769 159538 159538 159538 159538 159538 159538 79769 7...
// Output
// 159538
// Answer
// 79769
// -------------------------------
// int main()  
// { 
//      FAST_INP;
//      int t; 
//      cin >> t;
//      unordered_set<long long> s,s2;
//      vector<long long> l;
//      long long a[t], ans=0;
//      for(int i=0;i<t;i++) {
//      	cin >> a[i];
//      	s.insert(a[i]);
//  	}
//     if(t==2){
//         cout << lcm(a[0],a[1]) << "\n";
//         return 0;
//     }
     
//      for(auto it=s.begin();it!=s.end();it++){
//    		for(auto jt=it;jt!=s.end();jt++){
//  		    if(it==jt) continue;
//  			s2.insert(lcm(*it,*jt));
//  		}
//  	}
   
//  	for(auto it=s2.begin();it!=s2.end();it++){
//  		ans=gcd(*it,ans);
//  	}
//      cout << ans;
//      return 0;
// } 
