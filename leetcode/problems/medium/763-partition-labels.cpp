/*
Partition Labels

A string S of lowercase English letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

Example 1:

Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
 

Note:

S will have length in range [1, 500].
S will consist of lowercase English letters ('a' to 'z') only.
*/

class Solution {
public:
    vector<int> partitionLabels(string S) {
        int cnt[26]={0}, n=(int)S.size();
        // find the last index of each character
        for(int i=0;i<n;i++) cnt[S[i]-'a']=i;
        int r=-1, l=0;
        vector<int> ans;
        for(int i=0;i<n;i++){
            // if i reaches the last index of the character
            // add it to the ans
            // and update the l
            r=max(r,cnt[S[i]-'a']);
            if(i==r){
                ans.push_back(r-l+1);
                l=i+1;
            }
        }
        return ans;
    }
};