/*
Caesar Cipher
https://binarysearch.io/problems/Caesar-Cipher

You are given a lowercase alphabet string s, and an offset integer k. Replace every letter in s with a letter k positions further along the alphabet.

Note: If the letter overflows past a or z, it gets wrapped around the other side.

Example 1
Input

s = "abc"
k = 2
Output

"cde"
Explanation

"abc" gets moved 2 positions to the right.

Example 2
Input

s = "aaa"
k = -1
Output

"zzz"
Example 3
Input

s = "zzz"
k = 1
Output

"aaa"
Explanation

The "z" gets wrapped to "a"
*/


#include "solution.hpp"
using namespace std;


class Solution {
    public:
    string solve(string s, int k) {
        /*
        If k is negative, we need to find the positive modulo, which can be found by using (k%mod+mod)%mod.

        To the new character, simply add k with mod 26.

        (c-'a') converts char to int
        (c-'a')+k add the offset
        (((c-'a')+k)%26) after adding the offset, it may exceed 122 (which is z). Hence we need to take mod 26.
        (((c-'a')+k)%26)+'a' converts it back to char
        */
        string ans;
        if(k<0) k=(k%26+26)%26;
        for(char c:s) ans+=(((c-'a')+k)%26)+'a';
        return ans;
    }
};