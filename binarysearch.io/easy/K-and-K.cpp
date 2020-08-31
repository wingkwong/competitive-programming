#include "solution.hpp"
using namespace std;

class Solution {
    public:
    int solve(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int num: nums){
            if(num<=0&&binary_search(nums.begin(), nums.end(), -num)){
                return -num;
            }
        }
        return -1;
    }
};

class Solution2 {
    public:
    int solve(vector<int>& nums) {
        unordered_map<int,int> m;
        m[0]=1;
        int ans=-INT_MAX;
        for(int num: nums){
            if(m[-num]) ans=max(ans,abs(num));
            m[num]=1;
        }
        return ans==-INT_MAX?-1:ans;
    }
};
