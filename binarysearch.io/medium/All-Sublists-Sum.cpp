/*
All Sublists Sum
https://binarysearch.io/problems/All-Sublists-Sum


Given a list of integers nums, consider every contiguous sublist. Sum each of these sublists and return the sum of all these values. Mod the result by 10 ** 9 + 7.

Constraints

Length of nums is at most 5000.
Example 1
Input

nums = [2, 3, 5]
Output

33
Explanation

We have the following subarrays:

[2]
[3]
[5]
[2, 3]
[3, 5]
[2, 3, 5]
The sum of all of these is 33.
*/

#include "solution.hpp"
using namespace std;
typedef long long ll;

class Solution {
    public:
    int solve(vector<int>& nums) {
        // (n-i)+(n-i)*i
        // (n-i)(i+1)
        int n = (int)nums.size();
        ll ans=0, MOD=1e9+7;;
        for(int i=0;i<n;i++){
            ans=(ans+(nums[i]*(ll)(i+1)*(ll)(n-i)))%MOD;
        }
        return ans;
    }
};
