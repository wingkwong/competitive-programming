/*
Permutation in String
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False
 

Note:

The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].
*/

class Solution {
public:
    bool helper(vector<int> &m1, vector<int> &m2){
        for(int i=0;i<26;i++){
            // if they are not the same, return false immediately
            if(m1[i]!=m2[i]) return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        // if s1 size is greater than s2, then it cannot be a substring
        if(s1.size()>s2.size()) return false;
        // use two maps to store the occurrence of each letter 
        vector<int> m1(26,0),m2(26,0);
        // count the occurrence for s1 & s2 for the first window where the size is s1.size() 
        for(int i=0;i<s1.size();i++) {
            m1[s1[i]-'a']++; 
            m2[s2[i]-'a']++;
        }
        
        // sliding window approach
        for(int i=0;i<s2.size()-s1.size();i++){
            // check if m1 and m2 are the same within the window
            if(helper(m1,m2)) return true;
            // count the occurrence for the next window
            m2[s2[i+s1.size()]-'a']++;
            // each iteration shifts one character
            // uncount index s2[i]-'a' because it will be out of the boundary in the next iteration 
            m2[s2[i]-'a']--;
        }
        return helper(m1,m2);
    }
};