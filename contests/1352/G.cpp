/*
G. Special Permutation
time limit per test 2 seconds
memory limit per test 256 megabytes
inputstandard input
outputstandard output
A permutation of length 𝑛 is an array 𝑝=[𝑝1,𝑝2,…,𝑝𝑛], which contains every integer from 1 to 𝑛 (inclusive) and, moreover, each number appears exactly once. For example, 𝑝=[3,1,4,2,5] is a permutation of length 5.

For a given number 𝑛 (𝑛≥2), find a permutation 𝑝 in which absolute difference (that is, the absolute value of difference) of any two neighboring (adjacent) elements is between 2 and 4, inclusive. Formally, find such permutation 𝑝 that 2≤|𝑝𝑖−𝑝𝑖+1|≤4 for each 𝑖 (1≤𝑖<𝑛).

Print any such permutation for the given integer 𝑛 or determine that it does not exist.

Input
The first line contains an integer 𝑡 (1≤𝑡≤100) — the number of test cases in the input. Then 𝑡 test cases follow.

Each test case is described by a single line containing an integer 𝑛 (2≤𝑛≤1000).

Output
Print 𝑡 lines. Print a permutation that meets the given requirements. If there are several such permutations, then print any of them. If no such permutation exists, print -1.
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
       if(n<4) {
           cout << -1 << "\n";
           continue;
       }
        // print out all odd numbers. the diff for |pi-pi+1| is 2.
        for(int i=n;i>=1;i--) {
            if(i%2) cout << i << " ";
        }
        // the last odd number is 1, put 4 and 2 to link the even numbers
        cout << 4 << " " << 2 << " ";
        // print ut all even numbers. the diff for |pi-pi+1| is 2.
        for(int i=6;i<=n;i+=2) cout << i << " ";
        cout << "\n";
    }
    return 0;
} 

// 1 2 3 4 5 6 7 8 9 10
// 9 7 5 3 1 4 2 6 8 10

