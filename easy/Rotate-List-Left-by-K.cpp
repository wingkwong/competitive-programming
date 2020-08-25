#include "solution.hpp"
using namespace std;


class Solution {
    public:
    vector<int> solve(vector<int>& nums, int k) {
        int i, j, x, tmp, n=nums.size(); 
        k %= n; 
        int gcd=__gcd(k, n); 
        for (i=0; i<gcd; i++) { 
            tmp=nums[i]; 
            j=i; 
            while(true) { 
                x=j+k; 
                if (x>=n)  x-=n; 
                if (x==i)  break; 
                nums[j]=nums[x]; 
                j=x; 
            } 
            nums[j]=tmp; 
        } 
        return nums;
    }
};
