/*
Longest Substring with At Least K Repeating Characters

Find the length of the longest substring T of a given string (consists of lowercase letters only) such that every character in T appears no less than k times.

Example 1:

Input:
s = "aaabb", k = 3

Output:
3

The longest substring is "aaa", as 'a' is repeated 3 times.
Example 2:

Input:
s = "ababbc", k = 2

Output:
5

The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
*/

class Solution {
public:
    int longestSubstring(string s, int k) {
        int sz = (int)s.size();
        if(sz<k) return 0;
        int c[26]={0};
        // find the occurence of each character in S
        for(int i=0;i<sz;i++) c[s[i]-'a']++;
        int j=0;
        // find the largest index of longest substring 
        while(j<sz&&c[s[j]-'a']>=k) j++;
        // if it reaches to the end, return the size
        if(j==sz) return sz;
        // find the max longest substring for S[0..j] and S[j+1..sz]
        return max(longestSubstring(s.substr(0,j),k), longestSubstring(s.substr(j+1,sz),k));
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();