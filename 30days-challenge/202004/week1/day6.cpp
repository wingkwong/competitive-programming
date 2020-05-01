/*
Group Anagrams

Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for(string s: strs){
            string tmp=s;
            // sort each input
            sort(s.begin(), s.end());
            // and push to a map as key with the original value
            m[s].push_back(tmp);
        }
        vector<vector<string>> ans;
        // push each groups to ans
        for(auto k: m) ans.push_back(k.second);
        return ans;
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();