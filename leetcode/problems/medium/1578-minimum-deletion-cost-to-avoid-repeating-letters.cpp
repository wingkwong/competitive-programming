/*
Minimum Deletion Cost to Avoid Repeating Letters
https://leetcode.com/problems/minimum-deletion-cost-to-avoid-repeating-letters/


Given a string s and an array of integers cost where cost[i] is the cost of deleting the character i in s.

Return the minimum cost of deletions such that there are no two identical letters next to each other.

Notice that you will delete the chosen characters at the same time, in other words, after deleting a character, the costs of deleting other characters will not change.

 

Example 1:

Input: s = "abaac", cost = [1,2,3,4,5]
Output: 3
Explanation: Delete the letter "a" with cost 3 to get "abac" (String without two identical letters next to each other).
Example 2:

Input: s = "abc", cost = [1,2,3]
Output: 0
Explanation: You don't need to delete any character because there are no identical letters next to each other.
Example 3:

Input: s = "aabaa", cost = [1,2,3,4,1]
Output: 2
Explanation: Delete the first and the last character, getting the string ("aba").
 

Constraints:

s.length == cost.length
1 <= s.length, cost.length <= 10^5
1 <= cost[i] <= 10^4
s contains only lowercase English letters.
*/

class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int ans=0, sum=0, c=cost[0], mx=cost[0], last=0;
        char cur=s[0];
        // remove all consecutive duplicates and leave one with the max cost
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]){
                c+=cost[i];
                mx=max(cost[i],mx);
                last=1;
            } else {
                ans+=c-mx;
                c=cost[i];
                mx=cost[i];
                last=0;
            }
        }
        // edge case
        if(last) ans+=c-mx;
        return ans;
    }
};

// same idea but shorter 
class Solution2 {
public:
    int minCost(string s, vector<int>& cost) {
        int res = 0, max_cost = 0, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (i > 0 && s[i] != s[i - 1]) max_cost = 0;
            res += min(max_cost, cost[i]);
            max_cost = max(max_cost, cost[i]);
        }
        return res;
    }
};