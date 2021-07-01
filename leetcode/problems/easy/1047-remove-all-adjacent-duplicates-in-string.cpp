/*
Remove All Adjacent Duplicates In String
https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

We repeatedly make duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

 

Example 1:

Input: s = "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
Example 2:

Input: s = "azxxzy"
Output: "ay"
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
*/

class Solution {
public:
    string removeDuplicates(string s) {
    	string ans;
        for(char c : s) {
        	if(ans.size() && ans.back() == c) ans.pop_back();
        	else ans.push_back(c);
        }
        return ans;
    }
};
abccba

class Solution2 {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(char c : s) {
            int skip = 0;
            while(!st.empty() && st.top() == c) {
                skip = 1;
                st.pop();
            }
            if(!skip) st.push(c);
        }
        string ans;
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};