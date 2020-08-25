#include "solution.hpp"
using namespace std;


class Solution {
    public:
    int solve(int a, int b, int c) {
        int ans=1;
        if(a==b&&b==c) return ans;
        if(a==b) ans*=c;
        else if(b==c) ans*=a;
        else if(a==c) ans*=b;
        else ans*=a*b*c;
        return ans;
    }
};
