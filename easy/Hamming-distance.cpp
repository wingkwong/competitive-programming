#include "solution.hpp"
using namespace std;


class Solution {
    public:
    int solve(int x, int y) {
        int z = x^y, ans=0;
        while(z){
            ans+=z&1;
            z>>=1;
        }
        return ans;
    }
};