#include "solution.hpp"
using namespace std;


class Solution {
    public:
    vector<string> solve(string s, int n) {
        vector<string> ans;
        for(int i=0;i<s.size();i+=n){
            ans.push_back(s.substr(i,n));
        }
        return ans;
    }
};
