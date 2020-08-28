#include "solution.hpp"
using namespace std;


class Solution {
    public:
    bool solve(string s0, string s1) {
        int i=0, j=0, cnt=0, m=s0.size(), n=s1.size();
        if(m-1!=n) return false;
        while(i<m||j<n){
            if(s0[i]==s1[j]) i++, j++;
            else cnt++, i++;
        }
        return cnt==1;
    }
};
