/*
Codeforces Beta Round #1 - A. Theatre Square
https://codeforces.com/contest/1/problem/A
*/
#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    long long n,m,a,r,c;
    cin >> n >> m >> a;
    // calculate how many flagstones are needed
    r=n/a;
    c=m/a;
    //* * * * * * * 
	//* * * * * * *
	//* * * * * * *
	//* * * * * * *
	//* * * * * * *
	//* * * * * * *
	//* * * * * * *
	// if there is a remainder, add an extra one
    if(n%a) r++;
    if(m%a) c++;
    cout << r*c << "\n";
    return 0;
} 


