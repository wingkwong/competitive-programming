#include "solution.hpp"
using namespace std;


class Solution {
    public:
    bool ok(int x){
        while(x){
            int d = x%10;
            if(d==3||d==6||d==9) return true;
            x/=10;
        }
        return false;
    }
    vector<string> solve(int n) {
        vector<string> ans;
        for(int i=1;i<=n;i++){
            if(i%3==0||ok(i)) ans.push_back("clap");
            else ans.push_back(to_string(i));
        }
        return ans;
    }
};
