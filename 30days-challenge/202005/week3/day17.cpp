/*
Find All Anagrams in a String

Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ss(26,0),pp(26,0),ans;
        for(char ch: p) pp[ch-'a']++;
        int psz=(int)p.size();
        for(int i=0;i<s.size();i++){
            // Example: s: "cbaebabacd" p: "abc"
            // psz is 3, for 0..psz-1, we add the character to ss
            if(i<psz-1){
                ss[s[i]-'a']++;
            }else{
                // when it reaches psz, we need to check if i-psz+1 is an anwser or not
                ss[s[i]-'a']++;
                // if they are same, then i-psz+1 is an answer
                if(ss==pp) ans.push_back(i-psz+1);
                // the current window for i=2 is cba, and the next window is bae
                // hence, reset the character out of the window
                ss[s[i-psz+1]-'a']--;
            }
        }
        return ans;
    }
};
static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();