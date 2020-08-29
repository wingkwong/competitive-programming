#include "solution.hpp"
using namespace std;

// FASTER
class Solution {
    public:
    int solve(vector<int>& nums, int k) {
        int m = nums.size();
        unordered_map<int,int> mp;
        while(k>=0&&k<m&&!mp.count(k)){
            mp[k]=1;
            k=nums[k];
        }
        return k>=0&&k<m?-1:mp.size();
    }
};


class Solution {
    public:
    int solve(vector<int>& nums, int k) {
        int m = nums.size(), ans=0, cycle=0;
        if(!m) return ans;
        vector<int> vis(1e6,0);
        while(1){
            if(k>=m||vis[k]) {
                cycle^=vis[k];
                break;
            }
            vis[k]=1, k=nums[k], ans++;
        }
        return cycle?-1:ans;
    }
};
