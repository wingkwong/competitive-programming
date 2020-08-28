#include "solution.hpp"
using namespace std;


class Solution {
    public:
    bool solve(string s0, string s1) {
        int m=s0.size(), n=s1.size();
        for(int i=0;i<min(m,n);i++){
            if(s0[i]!=s1[i]){
                if(m==n) return s0.substr(i+1)==s1.substr(i+1);
                else if(m<n) return s0.substr(i)==s1.substr(i+1);
                else return s0.substr(i+1)==s1.substr(i);
            }
        }
        return abs(m-n)<=1;
    }
};
