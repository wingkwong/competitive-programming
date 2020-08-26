/*
Is Subsequence

Given a string s and a string t, check if s is subsequence of t.

You may assume that there is only lower case English letters in both s and t. t is potentially a very long (length ~= 500,000) string, and s is a short string (<=100).

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:
s = "abc", t = "ahbgdc"

Return true.

Example 2:
s = "axc", t = "ahbgdc"

Return false.

Follow up:
If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has its subsequence. In this scenario, how would you change your code?

Credits:
Special thanks to @pbrother for adding this problem and creating all test cases.
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ssz=(int)s.size();
        int tsz=(int)t.size();
        int i=0,j=0;
        // two pointer approach
        for(;i<ssz&&j<tsz;j++){
            // if matched, move i to the next char in s
            if(s[i]==t[j]) i++;
        }
        // if i reaches the end, it means it is a subseqeunce
        return (i==ssz);
    }
};

class Solution2 {
public:
    bool isSubsequence(string s, string t) {
        // DP approach - similar to 1143. Longest Common Subsequence
        int m=(int)s.size(), n=(int)t.size();
        if(m==0) return true;
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1]) {
                    dp[i][j]=dp[i-1][j-1]+1;
                } else {
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n]==m;
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();