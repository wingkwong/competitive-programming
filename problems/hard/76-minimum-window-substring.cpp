/*
Minimum Window Substring

Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
Note:

If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
*/

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> m;
        for(char c:t) m[c]++;
        int cnt=t.size(),begin=0,end=0,minStart=0,minLen=INT_MAX;
        // move end pointer to locate a valid window
        while(end<s.size()){
            // if the char s[end] exists in the map, decrease the counter   
            // decrease m[s[end]], if char doesn't exist, m[s[end]] will be negative
            if(--m[s[end++]]>=0) cnt--;
            // cnt==0 means the window is valid
            while(cnt==0){
                // move start pointer to locate a smaller window
                if(end-begin<minLen){
                    minLen=end-begin;
                    minStart=begin;
                }
                // when char exists in t, increase the counter
                if(++m[s[begin++]]>0) cnt++;
            }
        }
        return minLen<INT_MAX?s.substr(minStart,minLen):"";
    } 
};