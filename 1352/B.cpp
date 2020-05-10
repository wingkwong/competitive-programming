/*
B. Same Parity Summands
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given two positive integers 𝑛 (1≤𝑛≤109) and 𝑘 (1≤𝑘≤100). Represent the number 𝑛 as the sum of 𝑘 positive integers of the same parity (have the same remainder when divided by 2).

In other words, find 𝑎1,𝑎2,…,𝑎𝑘 such that all 𝑎𝑖>0, 𝑛=𝑎1+𝑎2+…+𝑎𝑘 and either all 𝑎𝑖 are even or all 𝑎𝑖 are odd at the same time.

If such a representation does not exist, then report it.

Input
The first line contains an integer 𝑡 (1≤𝑡≤1000) — the number of test cases in the input. Next, 𝑡 test cases are given, one per line.

Each test case is two positive integers 𝑛 (1≤𝑛≤109) and 𝑘 (1≤𝑘≤100).

Output
For each test case print:

YES and the required values 𝑎𝑖, if the answer exists (if there are several answers, print any of them);
NO if the answer does not exist.
The letters in the words YES and NO can be printed in any case.
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
       // take either k-1 odd numbers or k-1 even numbers plus n-(k-1) or n-2*(k-1)
       // make sure n-(k-1) or n-2*(k-1) is positive
        int n1=n-2*(k-1);
        if(n1%2==0&&n1>0){
            // even
            cout << "YES\n";
            for(int i=0;i<k-1;i++) {
                cout << "2 ";
                n-=2;
            }
            cout << n << "\n";
            continue;
        } 
        
        int n2=n-(k-1);
        if(n2%2==1&&n2>0){
            // odd
            cout << "YES\n";
            for(int i=0;i<k-1;i++) {
                cout << "1 ";
                n-=1;
            }
            cout << n << "\n";
            continue;
        }
        cout << "NO\n";
    }
    return 0;
} 