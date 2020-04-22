/*
Reformat The String

Given alphanumeric string s. (Alphanumeric string is a string consisting of lowercase English letters and digits).

You have to find a permutation of the string where no letter is followed by another letter and no digit is followed by another digit. That is, no two adjacent characters have the same type.

Return the reformatted string or return an empty string if it is impossible to reformat the string.

Example 1:

Input: s = "a0b1c2"
Output: "0a1b2c"
Explanation: No two adjacent characters have the same type in "0a1b2c". "a0b1c2", "0a1b2c", "0c2a1b" are also valid permutations.
Example 2:

Input: s = "leetcode"
Output: ""
Explanation: "leetcode" has only characters so we cannot separate them by digits.
Example 3:

Input: s = "1229857369"
Output: ""
Explanation: "1229857369" has only digits so we cannot separate them by characters.
Example 4:

Input: s = "covid2019"
Output: "c2o0v1i9d"
Example 5:

Input: s = "ab123"
Output: "1a2b3"
*/

class Solution {
public:
    string reformat(string s) {
        string s1="",s2="",ans="";
        for(char ch : s){
            // s1 holds digits
            if(isdigit(ch)) s1+=ch;
            // s2 holds chars 
            else s2+=ch;
        }
        // no two adjacent characters have the same type
        int diff = s1.size()-s2.size();
        if(abs(diff)>1) return "";
        // take the largest one as s1 
        if(s2.size()>s1.size()) swap(s1,s2);
        int i=0, j=0;
        // use k to select a char from s1 or s2 alternately 
        bool k = true;
        while(i<s1.size()||j<s2.size()){
            if(k) ans+=s1[i++];
            else ans+=s2[j++];
            k=!k;
        }
        
        return ans;
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();