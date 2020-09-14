/*
Minimum String
https://binarysearch.io/problems/Minimum-String

You are given two strings s and t of equal length only consisting of lowercase letters. Assuming that you can first rearrange s into any order, return the minimum number of changes needed to turn s into t.

Example 1
Input

s = "ehyoe"
t = "hello"
Output

2
Explanation

We can shuffle "ehyoe" to be "heyeo" and then turn "y" and the 2nd "e" into "l"
*/

#include "solution.hpp"
using namespace std;


class Solution {
    public:
    int solve(string s, string t) {
        int cnt[26]={0},cnt2[26]={0};
        for(char c:t) cnt[c-'a']++;
        for(char c:s) cnt2[c-'a']++;
        int ans=0;
        for(int i=0;i<26;i++){
            if(cnt[i]>cnt2[i]) ans+=cnt[i]-cnt2[i];
        }
        return ans;
    }
};
