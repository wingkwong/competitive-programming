/*
Generalized Abbreviation
https://leetcode.com/problems/generalized-abbreviation/

A word's generalized abbreviation can be constructed by taking any number of non-overlapping substrings and replacing them with their respective lengths. For example, "abcde" can be abbreviated into "a3e" ("bcd" turned into "3"), "1bcd1" ("a" and "e" both turned into "1"), and "23" ("ab" turned into "2" and "cde" turned into "3").

Given a string word, return a list of all the possible generalized abbreviations of word. Return the answer in any order.

 

Example 1:

Input: word = "word"
Output: ["4","3d","2r1","2rd","1o2","1o1d","1or1","1ord","w3","w2d","w1r1","w1rd","wo2","wo1d","wor1","word"]
Example 2:

Input: word = "a"
Output: ["1","a"]
 

Constraints:

1 <= word.length <= 15
word consists of only lowercase English letters.
*/

class Solution {
public:
    vector<string> ans;
    void dfs(string& word, string abbr, int num, int i) {
        if(i == word.size()) {
            ans.push_back(abbr + (num > 0 ? to_string(num) : ""));
        } else {
            // either abbreviate or not 
            dfs(word, abbr + (num > 0 ? to_string(num) : "") + word[i], 0, i + 1);
            dfs(word, abbr, num + 1, i + 1);
        }
    }
    vector<string> generateAbbreviations(string word) {
        dfs(word, "", 0, 0);
        return ans;
    }
};