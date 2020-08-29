#include "solution.hpp"
using namespace std;


class Solution {
    public:
    string solve(int n) {
        string s=to_string(n), ans;
        int sz=(int)s.size(), j=0;
        for(int i=sz-1;i>=0;i--){
            ans=s[i]+ans;
            if(j&&i&&(j-i)%3==0) ans=","+ans;
            if((sz-i)==2) ans="."+ans, j=i;
        }
        return ans.size()==1?"0.0"+ans:ans;
    }
};
