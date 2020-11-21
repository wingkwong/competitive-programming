/*
Restore The Array

A program was supposed to print an array of integers. The program forgot to print whitespaces and the array is printed as a string of digits and all we know is that all integers in the array were in the range [1, k] and there are no leading zeros in the array.

Given the string s and the integer k. There can be multiple ways to restore the array.

Return the number of possible array that can be printed as a string s using the mentioned program.

The number of ways could be very large so return it modulo 10^9 + 7

 

Example 1:

Input: s = "1000", k = 10000
Output: 1
Explanation: The only possible array is [1000]
Example 2:

Input: s = "1000", k = 10
Output: 0
Explanation: There cannot be an array that was printed this way and has all integer >= 1 and <= 10.
Example 3:

Input: s = "1317", k = 2000
Output: 8
Explanation: Possible arrays are [1317],[131,7],[13,17],[1,317],[13,1,7],[1,31,7],[1,3,17],[1,3,1,7]
Example 4:

Input: s = "2020", k = 30
Output: 1
Explanation: The only possible array is [20,20]. [2020] is invalid because 2020 > 30. [2,020] is ivalid because 020 contains leading zeros.
Example 5:

Input: s = "1234567890", k = 90
Output: 34
 

Constraints:

1 <= s.length <= 10^5.
s consists of only digits and doesn't contain leading zeros.
1 <= k <= 10^9.
*/

class Solution {
public:
    int dp[100001] = {};
    int dfs(string &s, int i, int k) {
        if (i == s.size())
            return 1;
        if (s[i] == '0')
            return 0;
        if (!dp[i]) {
            for (long sz = 1, num = 0; i + sz <= s.size(); ++sz) {
                num = num * 10 + s[i + sz - 1] - '0';
                if (num > k)
                    break;
                dp[i] = (dp[i] + dfs(s, i + sz, k)) % 1000000007;
            }
        }
        return dp[i];
    }
    int numberOfArrays(string s, int k) {
        return dfs(s, 0, k);
    }
};

class Solution2 {
public:
    int numberOfArrays(string s, int k) {
        int n = s.size();
        vector<int> dp(n+1,0);
        int mod = 1E9+7;
        dp[n]=1;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0') continue;
            string str="";
            str+=s[i];
            int j=i+1;
            while(j<=n && stol(str)<=k){
                dp[i]+=dp[j];
                dp[i]%=mod;
                if(j<n) str+=s[j];
                j++;
            }
        }
        return dp[0];
    }
};
static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();