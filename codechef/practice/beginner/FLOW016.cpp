/*
CodeChef - Practice(Beginner) - GCD and LCM
https://www.codechef.com/problems/FLOW016
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;

ll gcd(int a, int b){
	return b?gcd(b,a%b):a;
}

ll lcm(int a, int b) {
	return a/gcd(a,b)*b;
}

int main()  
{ 
    FAST_INP;
    int t,a,b; cin >> t;
    while(t--){
    	cin >> a >> b;
    	cout << gcd(a,b) << " " << lcm(a,b) << endl;
	}
    return 0;
} 
