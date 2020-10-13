/*
List Partitioning
https://binarysearch.com/problems/List-Partitioning

Given a list of strings strs, containing the strings "red", "green" and "blue", partition the list so that the red come before green, which come before blue.

Constraints

n ≤ 100,000 where n is the length of strs.
This should be done in \mathcal{O}(n)O(n) time.

Bonus: Can you do it in \mathcal{O}(1)O(1) space? That is, can you do it by only rearranging the list (i.e. without creating any new strings)?

Example 1
Input

strs = ["green", "blue", "red", "red"]
Output

["red", "red", "green", "blue"]
*/

#include "solution.hpp"
using namespace std;

class Solution {
    public:
    vector<string> solve(vector<string>& strs) {
        int red=0, blue=0, green=0;
        for(int i=0;i<strs.size();i++) {
            red+=strs[i]=="red";
            green+=strs[i]=="green";
            blue+=strs[i]=="blue";
        }
        vector<string> ans;
        for(int i=0;i<red;i++) ans.push_back("red");
        for(int i=0;i<green;i++) ans.push_back("green");
        for(int i=0;i<blue;i++) ans.push_back("blue"); 
        return ans;
    }
};