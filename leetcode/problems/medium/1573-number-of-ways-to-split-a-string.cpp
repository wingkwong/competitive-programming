/*
Number of Ways to Split a String
https://leetcode.com/problems/number-of-ways-to-split-a-string/

Given a binary string s (a string consisting only of '0's and '1's), we can split s into 3 non-empty strings s1, s2, s3 (s1+ s2+ s3 = s).

Return the number of ways s can be split such that the number of characters '1' is the same in s1, s2, and s3.

Since the answer may be too large, return it modulo 10^9 + 7.

 

Example 1:

Input: s = "10101"
Output: 4
Explanation: There are four ways to split s in 3 parts where each part contain the same number of letters '1'.
"1|010|1"
"1|01|01"
"10|10|1"
"10|1|01"
Example 2:

Input: s = "1001"
Output: 0
Example 3:

Input: s = "0000"
Output: 3
Explanation: There are three ways to split s in 3 parts.
"0|0|00"
"0|00|0"
"00|0|0"
Example 4:

Input: s = "100100010100110"
Output: 12
 

Constraints:

s[i] == '0' or s[i] == '1'
3 <= s.length <= 10^5
*/


// #math #combination 
class Solution {
public:
    int numWays(string s) {
        int n = s.size(), mod=1e9+7;
        vector<int> v;
        // store the index of 1
        for(int i=0;i<n;i++) if(s[i]=='1') v.push_back(i);
        int x = v.size();
        // case 1: number of 1s is not divisibe by 3
        if(x%3) return 0; 
        // case 2: number of 1s is 1
        // choice to put the first separator is n-1
        // choice to put the first separator is n-2
        // divide by 2 to remove the repeated case
        if(x==0) return ((long long)(n-2)*(n-1)/2)%mod; 
        // case 3: numer of 1s is divisibe by 3
        return ((long long)(v[(x/3)]-v[(x/3)-1])*(v[2*(x/3)]-v[2*(x/3)-1]))%mod;
    }
};