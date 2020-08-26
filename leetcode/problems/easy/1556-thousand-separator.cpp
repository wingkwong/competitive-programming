/*
Thousand Separator

Given an integer n, add a dot (".") as the thousands separator and return it in string format.

Example 1:

Input: n = 987
Output: "987"
Example 2:

Input: n = 1234
Output: "1.234"
Example 3:

Input: n = 123456789
Output: "123.456.789"
Example 4:

Input: n = 0
Output: "0"
 

Constraints:

0 <= n < 2^31
*/

class Solution {
public:
    string thousandSeparator(int n) {
        string s = to_string(n), ans;
        int sz = s.size();
        for(int i=0;i<sz;i++){
            if(i&&(sz-i)%3==0) ans+='.';
            ans+=s[i];
        }
        return ans;
    }
};

class Solution2 {
public:
    string thousandSeparator(int n) {
        string s = to_string(n), ans;
        int cnt=0, sz=s.size();
        reverse(s.begin(),s.end());
        for(int i=0;i<sz;i++){
            if(cnt&&cnt%3==0) ans+='.';
            ans+=s[i], cnt++;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};