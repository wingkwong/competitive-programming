/*
A. A+B (Trial Problem)
time limit per test1 second
memory limit per test: 256 megabytes
inputstandard input
outputstandard output
You are given two integers 𝑎 and 𝑏. Print 𝑎+𝑏.

Input
The first line contains an integer 𝑡 (1≤𝑡≤104) — the number of test cases in the input. Then 𝑡 test cases follow.

Each test case is given as a line of two integers 𝑎 and 𝑏 (−1000≤𝑎,𝑏≤1000).

Output
Print 𝑡 integers — the required numbers 𝑎+𝑏.

Example
input
4
1 5
314 15
-99 99
123 987

output
6
329
0
1110
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
int main()  
{ 
    FAST_INP;
    int t,a,b; 
    cin >> t;
    while(t--){
        // take two input values
        cin >> a >> b;
        // add them together
        cout << (a+b) << "\n";
    }
    return 0;
} 