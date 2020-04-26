/*
Coin Change

You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3 
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Note:
You may assume that you have an infinite number of each kind of coin.
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int sz = (int)coins.size();
        int max = amount+1;
        vector<int> dp(max,max);
        dp[0]=0;
        // for each amount
        for(int i=1;i<=amount;i++){
            // for each coin
            for(int j=0;j<sz;j++){
                // only take the coin which is less than the amount
                if(coins[j]<=i) {
                    // take the minimum count for amount i
                    dp[i] = min(dp[i], dp[i-coins[j]]+1);
                }
            }
        }
        // if that amount of money cannot be made up by any combination of the coins, return -1.
        return dp[amount]>amount?-1:dp[amount];
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();