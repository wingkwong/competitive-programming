#include "solution.hpp"
using namespace std;


class Solution {
    public:
    int solve(int n) {
        int ans=0;
        for(int i=1;n;i+=2,n--) ans+=i;
        return ans;
    }
};


class Solution {
    public:
    int solve(int n) {
        // (n/2)(2+(n-1)*2) 
        return n*n;
    }
};
