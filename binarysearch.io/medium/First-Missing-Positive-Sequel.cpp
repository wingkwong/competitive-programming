#include "solution.hpp"
using namespace std;


class Solution {
    public:
    int solve(vector<int>& arr) {
        int n = arr.size();
        for(int i=0;i<n;i++){
            int num = arr[i];
            while(num>0&&num<=n&&arr[num-1]!=num){
                swap(arr[num-1], num);
            }
        }
        for(int i=0;i<n;i++){
            if(arr[i]!=i+1) return i+1;
        }
        return n+1;
    }
};
