/*
Bold Words in String
https://leetcode.com/problems/bold-words-in-string/

Given a set of keywords words and a string S, make all appearances of all keywords in S bold. Any letters between <b> and </b> tags become bold.

The returned string should use the least number of tags possible, and of course the tags should form a valid combination.

For example, given that words = ["ab", "bc"] and S = "aabcd", we should return "a<b>abc</b>d". Note that returning "a<b>a<b>b</b>c</b>d" would use more tags, so it is incorrect.

Constraints:

words has length in range [0, 50].
words[i] has length in range [1, 10].
S has length in range [0, 500].
All characters in words[i] and S are lowercase letters.
Note: This question is the same as 616: https://leetcode.com/problems/add-bold-tag-in-string/
*/

class Solution {
public:
    string boldWords(vector<string>& dict, string s) {
        vector<int> marked(s.size(), 0);
        for(auto w : dict) {
            for(auto p = s.find(w, 0); p != string::npos; p = s.find(w, p + 1)) {
                fill(marked.begin() + p, marked.begin() + p + w.size(), 1);
            }
        }
        string ans;
        for(int i = 0; i < s.size(); i++) {
            if(marked[i] && (!i || !marked[i - 1])) ans += "<b>";
            ans += s[i];
            if(marked[i] && (i == s.size() - 1 || !marked[i + 1])) ans += "</b>";
        }
        return ans;
    }
};