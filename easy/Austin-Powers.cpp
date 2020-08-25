#include "solution.hpp"
using namespace std;


class Solution {
    public:
    bool solve(int n) {
        return n&&(!(n&(n-1)));  
    }
};
