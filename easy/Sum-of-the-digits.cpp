#include "solution.hpp"
using namespace std;


class Solution {
    public:
    int solve(int num) {
       int ans=0;
       while(num){
           ans+=num%10;
           num/=10;
       }
       return ans;
    }
};
