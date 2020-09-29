/*
Given a string s containing brackets ( and ), return the minimum number of brackets that can be inserted so that the brackets are balanced.

Constraints

n ≤ 100,000 where n is the length of s
Example 1
Input

s = ")))(("
Output

5
Explanation

We can insert ((( to the front and )) to the end
*/

#include "solution.hpp"
using namespace std;

class Solution {
    public:
    int solve(string s) {
        int left=0, right=0; // no of left bracket and right bracket needed
        for(int i=0;i<s.size();i++){
            if(s[i]==')') {
                if(right) right--;
                else left++;
            } else {
                right++;
            }
        }
        return left+right;
    }
};