/*
Shortest-String
https://binarysearch.io/problems/Shortest-String

Given a string s consisting only of 1s and 0s, you can delete any two adjacent letters if they are different.

Return the length of the smallest string that you can make if you're able to perform this operation as many times as you want.

Example 1
Input

s = "11000"
Output

1
Explanation

After deleting "10" we get "100" and we can delete another "10" to get "0" which has a length of 1.
*/



#include "solution.hpp"
using namespace std;

class Solution {
    public:
    int solve(string s) {
        // the ans is the abs diff of the number of 0s and that of 1s
        int cnt[2]={0};
        for(auto c:s) cnt[c-'0']++;
        return abs(cnt[0]-cnt[1]);
    }
};


class Solution2 {
    public:
    int solve(string s) {
        stack<char> st;
        for(auto c:s){
           if(!st.empty()&&st.top()!=c) {
                st.pop();
                continue;
            }
            st.push(c);
        }
        return st.size();
    }
};
