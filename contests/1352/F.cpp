/*
F. Binary String Reconstruction
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
For some binary string 𝑠 (i.e. each character 𝑠𝑖 is either '0' or '1'), all pairs of consecutive (adjacent) characters were written. In other words, all substrings of length 2 were written. For each pair (substring of length 2), the number of '1' (ones) in it was calculated.

You are given three numbers:

𝑛0 — the number of such pairs of consecutive characters (substrings) where the number of ones equals 0;
𝑛1 — the number of such pairs of consecutive characters (substrings) where the number of ones equals 1;
𝑛2 — the number of such pairs of consecutive characters (substrings) where the number of ones equals 2.
For example, for the string 𝑠="1110011110", the following substrings would be written: "11", "11", "10", "00", "01", "11", "11", "11", "10". Thus, 𝑛0=1, 𝑛1=3, 𝑛2=5.

Your task is to restore any suitable binary string 𝑠 from the given values 𝑛0,𝑛1,𝑛2. It is guaranteed that at least one of the numbers 𝑛0,𝑛1,𝑛2 is greater than 0. Also, it is guaranteed that a solution exists.

Input
The first line contains an integer 𝑡 (1≤𝑡≤1000) — the number of test cases in the input. Then test cases follow.

Each test case consists of one line which contains three integers 𝑛0,𝑛1,𝑛2 (0≤𝑛0,𝑛1,𝑛2≤100; 𝑛0+𝑛1+𝑛2>0). It is guaranteed that the answer for given 𝑛0,𝑛1,𝑛2 exists.

Output
Print 𝑡 lines. Each of the lines should contain a binary string corresponding to a test case. If there are several possible solutions, print any of them.
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int t,n0,n1,n2;
    cin >> t;
    while(t--){
       cin >> n0 >> n1 >> n2;
       
    }
    return 0;
} 