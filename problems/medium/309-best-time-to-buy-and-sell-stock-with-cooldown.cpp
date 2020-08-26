/*
Best Time to Buy and Sell Stock with Cooldown

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

Input: [1,2,3,0,2]
Output: 3 
Explanation: transactions = [buy, sell, cooldown, buy, sell]
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<2) return 0;
        // profit at index i for 3 states - rest, buy & sell
        vector<int> s0(n,0), s1(n,0), s2(n,0);
        // s0 -> s1 -> s2 -> s0 ..
        // s0 - rest -> (s0/s1)
        // s1 - buy  -> (s1/s2)
        // s2 - sell -> (s0)
        s0[0]=0;
        s1[0]=-prices[0];
        s2[0]=INT_MIN;
        for(int i=1;i<n;i++){
            s0[i]=max(s0[i-1],s2[i-1]);
            s1[i]=max(s1[i-1],s0[i-1]-prices[i]);
            s2[i]=s1[i-1]+prices[i];
        }
        return max(s0[n-1],s2[n-1]);
    }
};

class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        // simplified Solution1
        int n = prices.size();
        if(n<2) return 0;
        // profit at index i for 3 states - rest, buy & sell
        int rest=0, buy=-prices[0], sell=INT_MIN;
        // s0 -> s1 -> s2 -> s0 ..
        // s0 - rest -> (s0/s1)
        // s1 - buy  -> (s1/s2)
        // s2 - sell -> (s0)
        for(int i=1;i<n;i++){
            int prev_sell=sell;
            sell=buy+prices[i];
            buy=max(buy,rest-prices[i]);
            rest=max(rest, prev_sell);
        }
        return max(rest,sell);
    }
};


