#include "solution.hpp"
using namespace std;


class Solution {
    public:
    vector<int> solve(vector<int>& nums) {
        set<int> s;
        vector<int> ans;
        for(int n:nums) s.insert(n);
        for(int n:nums) ans.push_back(s.size()-distance(s.begin(),s.find(n))-1);
        return ans;
    }
};
