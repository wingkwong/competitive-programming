#include "solution.hpp"
using namespace std;


class Solution {
    public:
    bool solve(string s0, string s1) {
        if(s0==s1) return true;
        string s = s0;
        for(int i=0;i<s.size();i++){
            string s = s0.substr(i+1) + s0.substr(0,i+1);
            if(s==s1) return true;
        }
        return false;
    }
};
