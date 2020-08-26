#include "solution.hpp"
using namespace std;


class Solution {
    public:
    string solve(string s) {
        string ans;
        ans+=s[0];
        for(int i=1;i<s.size();i++){
            if(s[i]!=s[i-1]){
                ans+=s[i];
            }
        }
        return ans;
    }
};
