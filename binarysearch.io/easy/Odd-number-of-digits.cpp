#include "solution.hpp"
using namespace std;


class Solution {
    public:
    int oddDigit(int n){
        int d=0;
        while(n){
            d++;
            n/=10;
        }
        return d&1;
    }
    
    int solve(vector<int>& nums) {
       int ans=0;
       for(int num:nums) ans+=oddDigit(num);
       return ans;
    }
};
