/*
July Circuits '20 - Cutting a material
https://www.hackerearth.com/problem/algorithm/pizza-cutting-2e11a081/
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

long long solve(long long n){
    // The Lazy Caterer’s Problem
    // f(n) = n + f(n-1)
    // f(n) = n + n-1 + n-2 + ...... + 1 + f(0)
    // f(n) = (n*(n+1))/2 + 1
	return (n*n+n+2)/2;
}

int main()  
{ 
    FAST_INP;
    long long n,t;
    cin >> t;
    while(t--){
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
} 