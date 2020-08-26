#include "solution.hpp"
using namespace std;


class Solution {
    public:
    string solve(string s) {
        char cur=s[0];
        string ans;
        ans+=cur;
        for(int i=1;i<s.size();i++){
            if(s[i]==cur) continue;
            cur=s[i];
            ans+=s[i];
        }
        return ans;
    }
};
