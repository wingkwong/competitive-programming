#include "solution.hpp"
using namespace std;


class Solution {
    public:
    vector<int> solve(int n) {
        vector<int> ans;
        int prev = 1; 
        ans.push_back(prev);
        for (int i=1;i<=n;i++) { 
            int curr=(prev*(n-i+1))/i; 
            ans.push_back(curr);
            prev=curr; 
        } 
        return ans;
    }
};
