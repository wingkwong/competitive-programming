#include "solution.hpp"
using namespace std;


class Solution {
    public:
    int solve(vector<int>& arr) {
        int l=0, r=arr.size()-1;
        while(r>l+1){
            int m=l+(r-l)/2;
            if(arr[m]>arr[l]) l=m;
            else if(arr[m]<arr[l]) r=m;
        }
        return max(arr[l],arr[r]);
    }
};
