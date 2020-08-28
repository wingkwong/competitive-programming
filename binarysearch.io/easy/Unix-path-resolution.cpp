#include "solution.hpp"
using namespace std;


class Solution {
    public:
    vector<string> solve(vector<string>& path) {
        vector<string> ans;
        for(string s:path){
            if(s=="..") {
                if(ans.size()) {
                    ans.pop_back();
                }
            }
            else if(s!=".") ans.push_back(s);
        }
        return ans;
    }
};
