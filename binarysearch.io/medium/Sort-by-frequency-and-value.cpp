#include "solution.hpp"
using namespace std;


class Solution {
    public:
    vector<int> solve(vector<int>& nums) {
        unordered_map<int,int> m;
        vector<pair<int,int>> v;
        vector<int> ans;
        for(int num:nums) m[num]++;
        for(auto k:m) v.push_back({k.second,k.first});
        sort(v.rbegin(),v.rend());
        for(auto p:v) {
            for(int i=0;i<p.first;i++){
                ans.push_back(p.second);
            }
        }
        return ans;
    }
};
