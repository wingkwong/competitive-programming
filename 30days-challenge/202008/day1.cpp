/*
Detect Capital

Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.
 

Example 1:

Input: "USA"
Output: True
 

Example 2:

Input: "FlaG"
Output: False
 

Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.
*/

class Solution {
public:
    bool detectCapitalUse(string word) {
        int c1=0,c2=0,n=word.size();
        for(char c:word){
            if(c>='A'&&c<='Z') c1++;
            else c2++;
        }
        return (
            c1==n ||
            c2==n ||
            word[0]>='A'&&word[0]<='Z' && c2==n-1
        );
    }
};