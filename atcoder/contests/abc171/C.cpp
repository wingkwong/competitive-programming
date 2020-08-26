/*
AtCoder Beginner Contest 171 - C - One Quadrillion and One Dalmatians
https://atcoder.jp/contests/abc171/tasks/abc171_c
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    long long n;
    cin >> n;
	int arr[10000]; 
    int i=0; 
    // convert n to base 26
    while(n){ 
        arr[i]=n%26; 
        n=n/26; 
        i++; 
    } 
    // cant have 0 as A starts at 1
    // remove 0 
    // e.g 100 (base 26) -> 25 26 (base 26)
    for (int j=0; j<i-1; j++) { 
        if (arr[j]<=0) { 
            // borrow 26
            arr[j]+=26; 
            // substract 1 from next significant bit
            arr[j+1]=arr[j+1]-1; 
        } 
    } 
    // 25 26 (base 26) -> YZ
    for (int j=i; j>= 0; j--) { 
        if (arr[j]>0)  cout << char('a'+arr[j]-1); 
    } 
    cout << endl; 
    return 0;
} 
