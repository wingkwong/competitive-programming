/*
Coin Change 2

You are given coins of different denominations and a total amount of money. Write a function to compute the number of combinations that make up that amount. You may assume that you have infinite number of each kind of coin.

Example 1:

Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10] 
Output: 1
*/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<uint> dp(amount + 1);
        dp[0] = 1;
        // coins first because {2, 2, 1} is same as {1, 2, 2} and {2, 1, 2}
        // we only take one 
        // see 377. Combination Sum IV for opposite case
        for(auto c : coins) { 
            for(int i = 1; i <= amount; i++) {
                if(i < c) continue;
                dp[i] += dp[i - c];
            }
        }
        return dp.back();
    }
};