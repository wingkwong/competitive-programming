/*
Backspace String Compare

Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
Note:

1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.
Follow up:

Can you solve it in O(N) time and O(1) space?
*/


class Solution {
public:
    bool backspaceCompare(string S, string T) {
        return (f(S) == f(T));
    }
private:
    string f(string s){
        deque<char> q;
        int sz=s.size();
        // Traverse the string S.
        for(int i=0;i<sz;i++){
            // If any character except ‘#’ is found, push it at back in deque.
            if(s[i]!='#') q.push_back(s[i]);
            // If the character ‘#’ is found, pop a character from back of deque.
            else if(!q.empty()) q.pop_back();
        }
        // Initialise final string
        string ss="";
        // Finally pop all elements from front of deque to make new string.
        while(!q.empty()){
            ss+=q.front();
            q.pop_front();
        }
        return ss;
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();