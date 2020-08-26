#include "solution.hpp"
using namespace std;


class Solution {
    public:
    vector<int> solve(vector<int>& lst0, vector<int>& lst1) {
        vector<int> ans;
        ans.insert(ans.begin(),lst0.begin(),lst0.end());
        ans.insert(ans.end(),lst1.begin(),lst1.end());
        sort(ans.begin(),ans.end());
        return ans;
    }
};
