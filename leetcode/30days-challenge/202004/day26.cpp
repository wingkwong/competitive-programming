/*
Longest Common Subsequence

Given two strings text1 and text2, return the length of their longest common subsequence.

A subsequence of a string is a new string generated from the original string with some characters(can be none) deleted without changing the relative order of the remaining characters. (eg, "ace" is a subsequence of "abcde" while "aec" is not). A common subsequence of two strings is a subsequence that is common to both strings.

If there is no common subsequence, return 0.

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
 

Constraints:

1 <= text1.length <= 1000
1 <= text2.length <= 1000
The input strings consist of lowercase English characters only.
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int s1 = (int)text1.size();
        int s2 = (int)text2.size();
        vector<vector<int>> dp(s1+1, vector<int>(s2+1, 0));

        // input: "xabccde", "abc"
        //    xabccde
        //   00000000
        // a 00111111
        // b 00112222
        // c 00112223
        
        for(int i=1;i<=s1;i++){
            for(int j=1;j<=s2;j++){
                if(text1[i-1]==text2[j-1]){
                    // if matches, update the current LCS to LCS till i-1 and j-1 indexes plus 1
                    dp[i][j] = dp[i-1][j-1]+1;
                }else{
                    // take the largest LCS
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[s1][s2];
    }
    
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();