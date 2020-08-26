#include "solution.hpp"
using namespace std;


class Solution {
    public:
    int solve(string s) {
        int cnt=1, ans=0;
        char c=s[0];
        for(int i=1;i<s.size();i++){
            if(s[i]==c) {
                cnt++;
                ans=max(ans,cnt);
            }else{
                cnt=1;
                c=s[i];
            }
        }
        return ans;
    }
};
