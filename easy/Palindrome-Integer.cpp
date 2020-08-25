#include "solution.hpp"
using namespace std;


class Solution {
    public:
    bool solve(int num) {
        int i=num, n=0;
        while(i>0) {
            n=i%10+n*10;
            i/=10;
        }
        return n==num;
    }
};
