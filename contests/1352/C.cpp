/*
C. K-th Not Divisible by n
time limit per test 1 second
memory limit per test 256 megabytes
inputstandard input
outputstandard output
You are given two positive integers 𝑛 and 𝑘. Print the 𝑘-th positive integer that is not divisible by 𝑛.

For example, if 𝑛=3, and 𝑘=7, then all numbers that are not divisible by 3 are: 1,2,4,5,7,8,10,11,13…. The 7-th number among them is 10.

Input
The first line contains an integer 𝑡 (1≤𝑡≤1000) — the number of test cases in the input. Next, 𝑡 test cases are given, one per line.

Each test case is two positive integers 𝑛 (2≤𝑛≤109) and 𝑘 (1≤𝑘≤109).

Output
For each test case print the 𝑘-th positive integer that is not divisible by 𝑛.
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int t,n,k;
    cin >> t;
    while(t--){
        cin >> n >> k;
        // binary search approach
        // -------------------------
        int l=1,r=k*2,x;
        while(l<r){
            x=l+(r-l)/2;
            // 1,2...x
            if(x-x/n>=k) r=x;
            else l=x+1;
        }
        cout << l << "\n";

        // math approach
        // -------------------------
        // k + how many multiplier of n being shifted
        // cout << k + ((k-1)/(n-1))<< "\n";
    }
    return 0;
} 