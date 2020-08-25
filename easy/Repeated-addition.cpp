#include "solution.hpp"
using namespace std;


class Solution {
    public:
    int solve(int n) {
        return (n-1)%9+1;
    }
};

class Solution2 {
    public:
    int solve(int n) {
        int ans=n;
        while(ans>=10){
            int n = ans, d=0;
            while(n){
                d+=n%10;
                n/=10;
            }
            ans=d;
        }
        return ans;
    }
};
