#include "solution.hpp"
using namespace std;


class Solution {
    public:
    vector<vector<int>> solve(vector<int>& fighters, vector<vector<int>>& bosses) {
        vector<vector<int>> ans;
        int cnt1=0;
        for(int f:fighters) cnt1+=f;
        for(auto boss:bosses){
            int cnt2=0;
            for(int b:boss) cnt2+=b;
            if(cnt1<=cnt2) ans.push_back(boss);
        }
        return ans;
    }
};
