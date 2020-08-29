#include "solution.hpp"
using namespace std;


class Solution {
    public:
    int solve(int n) {
        int ans=1;
        for(int i=1;i<=n;i++) ans*=i;
        return ans;
    }
};
