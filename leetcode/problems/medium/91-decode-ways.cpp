/*
Decode Ways

A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
*/

class Solution {
public:
    char isValid(char a){
        return a!='0';
    }
    
    char isValid(char a, char b){
        return (a=='1'||(a=='2'&&b<='6'));
    }
    
    int numDecodings(string s) {
        int n=(int)s.size();
        if(n==0||s[0]=='0') return 0;
        if(n==1) return 1;
        int m1=1,m2=1,m;
        for(int i=1;i<n;i++){
            m=0;
            // validate the current character and the previous character
            if(!isValid(s[i])&&!isValid(s[i-1],s[i])) return 0;
            if(isValid(s[i])) m=m1;
            if(isValid(s[i-1],s[i])) m+=m2;
            m2=m1;
            m1=m;
        }
        return m;
    }
};