/*
Reverse The Number Problem Code: FLOW007

If an Integer N, write a program to reverse the given number.

Input
The first line contains an integer T, total number of testcases. Then follow T lines, each line contains an integer N.

Output
Display the reverse of the given number N.

Constraints
1 ≤ T ≤ 1000
1 ≤ N ≤ 1000000
Example
Input
4
12345
31203
2123
2300
Output
54321
30213
3212
32
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        int ans=0,r,e=to_string(n).length();
        // traverse each digit
        while(n){
            // update the exponent
            e--;
            // take last digit
            r=n%10;
            // if it is not zero, add 10^p*r to ans
            if(r!=0) ans+=pow(10,e)*r;
            // update n to check next digit
            n/=10;
        }
        cout << ans << "\n";
    }
    return 0;
} 