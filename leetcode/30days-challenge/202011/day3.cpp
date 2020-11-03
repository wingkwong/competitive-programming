/*
Consecutive Characters

Given a string s, the power of the string is the maximum length of a non-empty substring that contains only one unique character.

Return the power of the string.

Example 1:

Input: s = "leetcode"
Output: 2
Explanation: The substring "ee" is of length 2 with the character 'e' only.
Example 2:

Input: s = "abbcccddddeeeeedcba"
Output: 5
Explanation: The substring "eeeee" is of length 5 with the character 'e' only.
Example 3:

Input: s = "triplepillooooow"
Output: 5
Example 4:

Input: s = "hooraaaaaaaaaaay"
Output: 11
Example 5:

Input: s = "tourist"
Output: 1
*/

class Solution {
public:
    int maxPower(string s) {
        int ans=1,cnt=1;
        char cur=s[0];
        // traverse each character
        for(int i=1;i<s.size();i++){
            if(s[i]==cur){
                // if it is consecutive, add 1 to the counter
                // and check if it s greater than max length
                cnt++;
                ans=max(ans,cnt);
            } else {
                // if not, update cur and reset the counter
                cur=s[i];
                cnt=1;
            }
        }
        return ans;
    }
};

class Solution2 {
public:
    int maxPower(string s) {
        int n = (int) s.size(), ans = 1, cnt = 1;
        for(int i = 0; i + 1 < n; i++) {
            if(s[i] == s[i + 1]) {
                cnt++;
                ans = max(ans, cnt);
            } else {
                cnt = 1;
            }
        }
        return ans;
    }
};