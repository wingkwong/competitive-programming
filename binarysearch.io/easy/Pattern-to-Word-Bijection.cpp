/*
Pattern to Word Bijection
https://binarysearch.com/problems/Pattern-to-Word-Bijection

Given two strings s and p, return whether s follows the pattern in p. That is, return whether each character in p can map to a non-empty word such that it maps to s.

Constraints

n ≤ 100,000 where n is the length of s
Example 1
Input

s = "hello world world world hello"
p = "abbba"
Output

true
Explanation

We can map "a" = "hello" and "b" = "world".
*/

#include "solution.hpp"
using namespace std;

class Solution {
    public:
    bool solve(string s, string p) {
        unordered_map<string, int> m;
        istringstream iss(s);
        string ss; 
        int i = 0;
        while(iss>>ss){
            if(m.count(ss)) {
                if(m[ss]!=p[i]) return false;
            } else {
                for(auto& k: m) {
                    if(k.second == p[i]) return false;
                }
                m[ss]=p[i];
            }
            i++;
        }
        return true;
    }
};