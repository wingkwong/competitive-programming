/*
Repeated Deletion
https://binarysearch.io/problems/Repeated-Deletion

Given a string s, repeatedly delete the earliest consecutive duplicate characters.

Constraints

n ≤ 100,000 where n is the length of s.
Example 1
Input

s = "abbbaac"
Output

"c"
Explanation

"bbb" are the earliest consecutive duplicate characters which gets deleted. So we have "aaac".
"aaa" then gets deleted to end up with "c".
*/

#include "solution.hpp"
using namespace std;


class Solution {
    public:
    string solve(string s) {
        string st;
        st.push_back(s[0]);
        int i=1;
        // stack approach
        // if the current char match the previous one, look for the next which doesnt match
        // else push the current char and increase i
        // keep iterating it until i being out of bound
        while(i<s.size()){
            int j=i;
            while(s[j]==st.back()&&j<s.size()) j++;
            if(i==j) st.push_back(s[i++]);
            else {
                st.pop_back();
                i=j;
            }
        }
        return st;
    }
};
