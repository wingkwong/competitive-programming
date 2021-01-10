/*
Bitwise ORs of Subarrays

We have an array arr of non-negative integers.

For every (contiguous) subarray sub = [arr[i], arr[i + 1], ..., arr[j]] (with i <= j), we take the bitwise OR of all the elements in sub, obtaining a result arr[i] | arr[i + 1] | ... | arr[j].

Return the number of possible results. Results that occur more than once are only counted once in the final answer

 

Example 1:

Input: arr = [0]
Output: 1
Explanation: There is only one possible result: 0.
Example 2:

Input: arr = [1,1,2]
Output: 3
Explanation: The possible subarrays are [1], [1], [2], [1, 1], [1, 2], [1, 1, 2].
These yield the results 1, 1, 2, 1, 3, 3.
There are 3 unique values, so the answer is 3.
Example 3:

Input: arr = [1,2,4]
Output: 6
Explanation: The possible results are 1, 2, 3, 4, 6, and 7.
 

Constraints:

1 <= nums.length <= 5 * 104
0 <= nums[i] <= 109
*/

// AC
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        // (a1)
        // (a2) (a2 a1)
        // (a3) (a3 a2) (a3 a2 a1)
        // (a4) (a4 a3) (a4 a3 a2) (a4 a3 a2 a1)
        // ...
        vector<int> ans;
        int left = 0, right = 0;
        for(int a : arr) {
            ans.emplace_back(a);
            for(int i = left; i < right; i++) {
                int x = a | ans[i];
                if(x != ans.back()) {
                    ans.emplace_back(x);
                }
            }
            left = right;
            right = (int) ans.size();
        }
        return (int) unordered_set<int>(ans.begin(), ans.end()).size();
    }
};

// TLE
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        set<int> ans, cur;
        for(int a : arr) {
            set<int> cur2;
            for(int b : cur) cur2.insert(a | b);
            cur2.insert(a);
            cur = cur2;
            ans.insert(cur.begin(), cur.end());
        }
        return (int) ans.size();
    }
};