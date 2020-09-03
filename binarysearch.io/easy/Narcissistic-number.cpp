#include "solution.hpp"
using namespace std;


class Solution {
    public:
    bool solve(int n) {
        int d=n>0?(int)log10((double)n)+1:1;
        int ans=0, num=n;
        while(n){
            ans+=pow(n%10,d);
            n/=10;
        }
        return ans==num;
    }
};
