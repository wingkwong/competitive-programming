/*
Text-Editor
https://binarysearch.io/problems/Text-Editor

Given a string s representing characters typed into an editor, with "<-" representing a backspace, return the current state of the editor.

Example 1
Input

s = "abc<-z"
Output

"abz"
Explanation

The "c" got deleted by the backspace.

Example 2
Input

s = "<-x<-z<-"
Output

""
Explanation

All characters are deleted. Also note you can type backspace when the editor is empty as well.
*/

#include "solution.hpp"
using namespace std;


class Solution {
    public:
    string solve(string s) {
        string ans;
        for(int i=0;i<s.size();i++){
            if(i+1<s.size()&&s[i]=='<'&&s[i+1]=='-'){
                if(ans.size()) ans.pop_back();
                i++;
            } else {
                ans+=s[i];
            }
        }
        return ans;
    }
};
