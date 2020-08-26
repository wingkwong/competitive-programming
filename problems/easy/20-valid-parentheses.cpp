/*
Valid Parentheses

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        map<char,char> m;
        m.insert({'}', '{'});
        m.insert({']', '['});
        m.insert({')', '('});
        for(char c:s){
            if(c=='}'||c==']'||c==')'){
                // get the top element of the stack
                char t = st.empty()?'*':st.top();
                // check if it matches the corresponding pair
                if(m[c]!=t) return false; 
                st.pop();
            } else{
                // { or [ or ( 
                st.push(c);
            }
        }
        return st.empty();
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();