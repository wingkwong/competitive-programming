/*
Add Binary

Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

Each string consists only of '0' or '1' characters.
1 <= a.length, b.length <= 10^4
Each string is either "0" or doesn't contain any leading zero.
*/

class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.size()-1, j=b.size()-1, c=0;
        string ans="";
        while(i>=0||j>=0||c==1){
            // add 1 to c if it is '1'
            c+=i>=0?a[i--]-'0':0;
            c+=j>=0?b[j--]-'0':0;
            // if both is 1, c&1 returns 0, else 1
            ans=to_string(c&1)+ans;
            // update c 
            c>>=1;
        }
        return ans;
    }
};