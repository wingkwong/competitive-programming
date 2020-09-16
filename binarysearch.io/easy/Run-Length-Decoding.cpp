/*
Run-Length Decoding
https://binarysearch.io/problems/Run-Length-Decoding


Run-length encoding is a fast and simple method of encoding strings. The basic idea is to represent
repeated successive characters as a single count and character. For example, the string "AAAABBBCCDAA" would
be encoded as "4A3B2C1D2A".

Given a string s that's a run-length encoded string, return its decoded version.

Note: The original string is guaranteed not to have numbers in it.

Example 1
Input

s = "4A3B2C1D2A"
Output

"AAAABBBCCDAA"
*/

#include "solution.hpp"
using namespace std;


class Solution {
    public:
    string solve(string s) {
        // Check each character to see if it is a digit. If so, append it to num. 
        // When we see the first alphabet, use string initialisation to create the repeated successive characters 
        // and add them to ans.
        string ans, num;
        for(char c:s){
            if(isdigit(c)) num+=c;
            else {
                string ss(stoi(num),c);
                ans+=ss;
                num.clear();
            }
        }
        return ans;
    }
};
