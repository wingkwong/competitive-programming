#include "solution.hpp"
using namespace std;


class Solution {
    public:
    string solve(string s0, string s1) {
        int i=0, j=0, m=s0.size(), n=s1.size();
        string ans;
        while(i<m||j<n){
            if(i<m) ans+=s0[i++];
            if(j<n) ans+=s1[j++];
        }
        return ans;
    }
};
