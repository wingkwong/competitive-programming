/*
B. Square?
time limit per test1 second
memory limit per test: 256 megabytes
inputstandard input
outputstandard output
Vasya claims that he had a paper square. He cut it into two rectangular parts using one vertical or horizontal cut. Then Vasya informed you the dimensions of these two rectangular parts. You need to check whether Vasya originally had a square. In other words, check if it is possible to make a square using two given rectangles.

Input
The first line contains an integer 𝑡 (1≤𝑡≤104) — the number of test cases in the input. Then 𝑡 test cases follow.

Each test case is given in two lines.

The first line contains two integers 𝑎1 and 𝑏1 (1≤𝑎1,𝑏1≤100) — the dimensions of the first one obtained after cutting rectangle. The sizes are given in random order (that is, it is not known which of the numbers is the width, and which of the numbers is the length).

The second line contains two integers 𝑎2 and 𝑏2 (1≤𝑎2,𝑏2≤100) — the dimensions of the second obtained after cutting rectangle. The sizes are given in random order (that is, it is not known which of the numbers is the width, and which of the numbers is the length).

Output
Print 𝑡 answers, each of which is a string "YES" (in the case of a positive answer) or "NO" (in the case of a negative answer). The letters in words can be printed in any case (upper or lower).

Example
input
3
2 3
3 1
3 2
1 3
3 3
1 3

output
Yes
Yes
No
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    long long t,a1,a2,b1,b2;
    cin >> t;
    while(t--){
        cin >> a1 >> a2 >> b1 >> b2;
        // both rectangular parts must have a same length of either length or width
        // if the length is same, check the sum both width is equal to the length or not
        if(
            (a1==b1 && a1==(a2+b2)) ||
            (a1==b2 && a1==(a2+b1)) ||
            (a2==b1 && a2==(a1+b2)) ||
            (a2==b2 && a2==(a1+b1))
        ) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
} 