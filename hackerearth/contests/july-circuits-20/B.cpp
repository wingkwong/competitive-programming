/*
July Circuits '20 - Supernatural
https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/supernatural-cac54bc7/description/
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
 
ll ans=0;
 
bool isPrime(ll n) {
   for(ll i=2;i*i <= n; i++) {
      if(n%i==0) return false;
   }
   return true;
}
 
void solve(ll n) {
   if(n<=1) return;
   if(isPrime(n)) {
      if(n<10) ans++;
      return;
   }
   if(n<10) ans++;
   for(int i=2; i<10;i++) {
      if(n%i==0) solve(n/i);
   }  
}
int main()  
{ 
    FAST_INP;
    int n;
    cin >> n;
    solve(n);
    cout << ans << endl;
    return 0;
} 