#include "solution.hpp"
using namespace std;


class Solution {
    public:
    int solve(vector<int>& prices) {
        int sz = (int)prices.size();
        if(!sz) return 0;
        int minPrice=INT_MAX, maxPrice=INT_MIN;
        for(int i=0;i<sz;i++){
            minPrice=min(minPrice,prices[i]);
            maxPrice=max(maxPrice,prices[i]-minPrice);
        }
        return maxPrice;
    }
};
