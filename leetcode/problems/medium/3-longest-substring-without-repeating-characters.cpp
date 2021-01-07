/*
Longest Substring Without Repeating Characters

Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> m;
        int start = -1, maxLen = 0;
        for (int i = 0; i < s.size(); i++) {
            if (m.count(s[i])) start = max(start, m[s[i]]);
            m[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};

class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        vector<char> v;
        for(char c : s){
            auto it=find(v.begin(),v.end(),c);
            if(it!=v.end()){
                if(v.size()>ans)ans=v.size();
                v.erase(v.begin(),it+1);
            }
            v.push_back(c);
        }
        if(v.size()>ans)ans=v.size();
        return ans;
    }
};


static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();