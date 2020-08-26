/*
Sum of Digits Problem Code: FLOW006

You're given an integer N. Write a program to calculate the sum of all the digits of N.

Input
The first line contains an integer T, total number of testcases. Then follow T lines, each line contains an integer N.

Output
Calculate the sum of digits of N.

Constraints
1 ≤ T ≤ 1000
1 ≤ N ≤ 1000000
Example
Input
3 
12345
31203
2123
Output
15
9
8
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int t,n,ans;
    cin >> t;
    while(t--){
        cin >> n;
        ans=0;
        // traverse each digit
        while(n){
            // add the last digit to ans
            ans+=n%10;
            // divide by 10
            n/=10;
        }
        cout << ans << "\n";
    }
    return 0;
} 