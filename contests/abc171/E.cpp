/*
AtCoder Beginner Contest 171 - E - Red Scarf
https://atcoder.jp/contests/abc171/tasks/abc171_e
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
int main()  
{ 
    FAST_INP;
    int n,x=0; 
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    // x=a1^a2^a3^...^an
	for(int i=0;i<n;i++) x^=a[i];
    // take a1 as an example 
    // a1=a1^a2^a3^...^an^a1
    //   =a1^a1^a2^a3^...^an // rearrange the order. xor is cumulative 
    //   =a2^a3^...^an       // a1^a1=0 ... 0^x=x
	for(int i=0;i<n;i++) a[i]=x^a[i];
    // print the numbers
	for(int i=0;i<n;i++) cout << a[i] << " ";
    return 0;
} 
