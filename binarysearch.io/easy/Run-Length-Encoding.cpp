#include "solution.hpp"
using namespace std;


class Solution {
    public:
    string solve(string s) {
        string ans;
        for(int i=0;i<s.size();i++){
            int cnt=1;
            while(s[i]==s[i+1]&&i<s.size()-1) cnt++, i++;
            ans+=to_string(cnt);
            ans+=s[i];
        }
        return ans;
    }
};
