/*
camelCase
https://binarysearch.io/problems/camelCase

Given a list of strings words, concatenate the strings in camel case format.

Example 1
Input

words = ["java", "beans"]
Output

"javaBeans"
Example 2
Input

words = ["Go", "nasa"]
Output

"goNasa"

*/

#include "solution.hpp"
using namespace std;


class Solution {
    public:
    string solve(vector<string>& words) {
        string ans;
        for(string w:words){
            for(char& c:w) c=tolower(c);
            w[0]=toupper(w[0]);
            ans+=w;
        }
        ans[0]=tolower(ans[0]);
        return ans;
    }
};
