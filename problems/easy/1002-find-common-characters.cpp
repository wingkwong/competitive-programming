/*
Find Common Characters

Given an array A of strings made only from lowercase letters, return a list of all characters that show up in all strings within the list (including duplicates).  For example, if a character occurs 3 times in all strings but not 4 times, you need to include that character three times in the final answer.

You may return the answer in any order.

Example 1:

Input: ["bella","label","roller"]
Output: ["e","l","l"]
Example 2:

Input: ["cool","lock","cook"]
Output: ["c","o"]
 
Note:

1 <= A.length <= 100
1 <= A[i].length <= 100
A[i][j] is a lowercase letter
*/

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> ans;
        vector<int> v1(26,INT_MAX);
        for(string s:A){
            vector<int> v2(26,0);
            // count each character in s
            for(char c:s) v2[c-'a']++;
            // update each character occurrence
            // take the min one
            // if the character doesn't exist in A, vi[i] would be 0 where i is the index of that character
            for(int i=0;i<26;i++) v1[i]=min(v2[i],v1[i]);
        }
        
        // traverse a-z
        for(int i=0;i<26;i++){
            // a character may occurs mulitple times, traverse them all
            for(int j=0;j<v1[i];j++){
                // put each character to ans
                ans.push_back(string(1,i+'a'));
            }
        }
        return ans;
    }
};