/*
Diagonal Traverse II

Given a list of lists of integers, nums, return all elements of nums in diagonal order as shown in the below images.

Example 1:

Input: nums = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,4,2,7,5,3,8,6,9]
Example 2:

Input: nums = [[1,2,3,4,5],[6,7],[8],[9,10,11],[12,13,14,15,16]]
Output: [1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16]
Example 3:

Input: nums = [[1,2,3],[4],[5,6,7],[8],[9,10,11]]
Output: [1,4,2,5,3,8,6,9,7,10,11]
Example 4:

Input: nums = [[1,2,3,4,5,6]]
Output: [1,2,3,4,5,6]
 

Constraints:

1 <= nums.length <= 10^5
1 <= nums[i].length <= 10^5
1 <= nums[i][j] <= 10^9
There at most 10^5 elements in nums.
*/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int r = (int)nums.size(), k=0;
        vector<int> ans;
        unordered_map<int, vector<int>> m;
        for(int i=0;i<r;i++){
            int c = (int)nums[i].size();
            for(int j=0;j<c;j++){
                // numbers with equal sums of row and column indexes belong to the same diagonal.
                m[i+j].push_back(nums[i][j]);
                // store the max diagonal order
                k=max(k,i+j);
            }
        }
        // [0]: 1
        // [1]: 2-6
        // [2]: 3-7-8
        // ...
        for(int i=0;i<=k;i++){
            int d = (int)m[i].size();
            // push the diagonal elements in backwards
            for(int j=d-1;j>=0;j--){
                ans.push_back(m[i][j]);
            }
        }
        return ans;
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();
