class Solution {
public:
    // kSum template
    void KSum(int k, vector<int>& nums, int l, int r, int target, vector<vector<int>>& retVal, vector<int>& cur, int ci ) 
    {
        int i, mn, mx;
        int km1 = k-1;
        if (r-l+1<k) return;
        while (l<r) {
            mn = nums[l];
            mx = nums[r];
            if (mn+km1*mx<target) l++;
            else if (km1*mn+mx>target) r--;
            else if (k==2) {
                cur[ci] = mn;
                cur[ci+1] = mx;
                retVal.push_back( cur );
                l++;
                while (l<r&&nums[l]==mn) l++;
                r--;
                while (l<r&&nums[r]==mx) r--;
            } else {
                cur[ci]=mn;
                KSum(km1,nums,++l,r,target-mn,retVal,cur,ci+1);
                while (l<r&&nums[l]==nums[l-1]) l++;
            }
        }
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> v(4,0);
        sort(nums.begin(), nums.end());
        KSum(4,nums,0,nums.size()-1,target,ans,v,0);
        return ans;     
    }
};