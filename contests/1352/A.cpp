/*
A. Sum of Round Numbers
time limit per test 1 second
memory limit per test 256 megabytes
input standard input
output standard output
A positive (strictly greater than zero) integer is called round if it is of the form d00...0. 
In other words, a positive integer is round if all its digits except the leftmost (most significant) are equal to zero. 
In particular, all numbers from 1 to 9 (inclusive) are round.

For example, the following numbers are round: 4000, 1, 9, 800, 90. The following numbers are not round: 110, 707, 222, 1001.

You are given a positive integer 𝑛 (1≤𝑛≤104). Represent the number 𝑛 as a sum of round numbers using the minimum number of summands (addends). 
In other words, you need to represent the given number 𝑛 as a sum of the least number of terms, each of which is a round number.

Input
The first line contains an integer 𝑡 (1≤𝑡≤104) — the number of test cases in the input. Then 𝑡 test cases follow.

Each test case is a line containing an integer 𝑛 (1≤𝑛≤104).

Output
Print 𝑡 answers to the test cases. Each answer must begin with an integer 𝑘 — the minimum number of summands. Next, 𝑘 terms must follow, 
each of which is a round number, and their sum is 𝑛. The terms can be printed in any order. If there are several answers, print any of them.
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int n,t;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> ans;
        int p=1;
        // iterate each digit
        while(n){
            // if the digit is not 0, store the digit*power to ans
            if(n%10) ans.push_back(n%10*p);
            // multiply the power by 10
            p*=10;
            // check the next digit (from right to left)
            n/=10;
        }
        cout << ans.size() << "\n";
        for(int a:ans) cout << a << " " ;
        cout << "\n";
    }
    return 0;
} 