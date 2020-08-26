/*
Valid Palindrome

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false

*/

class Solution {
public:
    bool isPalindrome(string s) {
        int sz=(int)s.size();
        if(!sz) return true;
        int i=0,k=sz-1;
        while(i<k){
            // move to the first alphanumeric character
            if(!isalnum(s[i])){
                i++;
                continue;
            }
            // move to the first alphanumeric character
            if(!isalnum(s[k])){
                k--;
                continue;
            }
            // compare both characters, return false if they are not the same
            if(tolower(s[i++])!=tolower(s[k--])) {
                return false;
            }
        }
        return true;
    }
};

// A man, a plan, a canal: Panama
// amanaplanacanalpanama