/*
First Unique Character in a String

Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
*/

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> m;
        // add each char to a hashmap
        for(char c:s) ++m[c];
        for(int i=0;i<s.size();i++) {
            // m[s[i]] == 1 means it is an unique char for s[i]
            if(m[s[i]]==1) return i;
        }
        return -1;
    }
};
static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();