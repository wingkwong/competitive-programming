#include "solution.hpp"
using namespace std;


class Solution {
    public:
    string solve(int n) {
        string ans;
        for(int i=1;i<=n;i++){
            int j=n-i;
            string space(j,' ');
            string stair(i,'*');
            ans+=space+stair;
            if(i<n) ans+='\n';
        }
        return ans;
    }
};
