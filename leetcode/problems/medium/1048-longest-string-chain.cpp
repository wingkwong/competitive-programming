/*
Longest String Chain
https://leetcode.com/problems/longest-string-chain/

Given a list of words, each word consists of English lowercase letters.

Let's say word1 is a predecessor of word2 if and only if we can add exactly one letter anywhere in word1 to make it equal to word2. For example, "abc" is a predecessor of "abac".

A word chain is a sequence of words [word_1, word_2, ..., word_k] with k >= 1, where word_1 is a predecessor of word_2, word_2 is a predecessor of word_3, and so on.

Return the longest possible length of a word chain with words chosen from the given list of words.

 

Example 1:

Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chain is "a","ba","bda","bdca".
Example 2:

Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5
 

Constraints:

1 <= words.length <= 1000
1 <= words[i].length <= 16
words[i] only consists of English lowercase letters.
*/

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [&](string& a, string& b) {
            return a.size() < b.size();
        });
        unordered_map<string, int> dp;
        int ans = 0;
        for(auto w : words) {
            for(int i = 0; i < w.size(); i++) {
                string target = w.substr(0, i) + w.substr(i + 1);
                // ["a","b","ba","bca","bda","bdca"]
                // a
                // b
                // ca
                // ba
                // bc
                // da
                // ba
                // bd
                // dca
                // bca
                // bda
                // bdc
                dp[w] = max(dp[w], dp.find(target) == dp.end() ? 1 : dp[target] + 1);
            }
            ans = max(ans, dp[w]);
        }
        return ans;
    }
};