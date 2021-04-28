/*
Add Bold Tag in String
https://leetcode.com/problems/add-bold-tag-in-string/

Given a string s and a list of strings dict, you need to add a closed pair of bold tag <b> and </b> to wrap the substrings in s that exist in dict. If two such substrings overlap, you need to wrap them together by only one pair of closed bold tag. Also, if two substrings wrapped by bold tags are consecutive, you need to combine them.
Example 1:

Input: 
s = "abcxyz123"
dict = ["abc","123"]
Output:
"<b>abc</b>xyz<b>123</b>"
 

Example 2:

Input: 
s = "aaabbcc"
dict = ["aaa","aab","bc"]
Output:
"<b>aaabbc</b>c"
 

Constraints:

The given dict won't contain duplicates, and its length won't exceed 100.
All the strings in input have length in range [1, 1000].
Note: This question is the same as 758: https://leetcode.com/problems/bold-words-in-string/
*/

class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
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