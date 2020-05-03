/*
Check If a String Can Break Another String

Given two strings: s1 and s2 with the same size, check if some permutation of string s1 can break some permutation of string s2 or vice-versa (in other words s2 can break s1).

A string x can break string y (both of size n) if x[i] >= y[i] (in alphabetical order) for all i between 0 and n-1.

Example 1:

Input: s1 = "abc", s2 = "xya"
Output: true
Explanation: "ayx" is a permutation of s2="xya" which can break to string "abc" which is a permutation of s1="abc".
Example 2:

Input: s1 = "abe", s2 = "acd"
Output: false 
Explanation: All permutations for s1="abe" are: "abe", "aeb", "bae", "bea", "eab" and "eba" and all permutation for s2="acd" are: "acd", "adc", "cad", "cda", "dac" and "dca". However, there is not any permutation from s1 which can break some permutation from s2 and vice-versa.
Example 3:

Input: s1 = "leetcodee", s2 = "interview"
Output: true
 

Constraints:

s1.length == n
s2.length == n
1 <= n <= 10^5
All strings consist of lowercase English letters.
*/

class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        // sort s1 and s2
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        int c1=0,c2=0,sz=(int)s1.size();
        for(int i=0;i<sz;i++){
            // check how many word can be broken by s1
            if(s1[i]>=s2[i]) c1++;
            // check how many word can be broken by s2
            if(s2[i]>=s1[i]) c2++;
        }
        // if either one can break all words, return true
        return max(c1,c2)==sz;
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();