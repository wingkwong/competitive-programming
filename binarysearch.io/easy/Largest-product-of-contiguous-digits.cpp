/*
Largest product of contiguous digits
https://binarysearch.io/problems/Largest-product-of-contiguous-digits

Given two integers num and k, return the largest product of k contiguous digits in num.

Note: num is guaranteed to have >= k digits.

Example 1
Input

num = 41598671
k = 3
Output

432
Explanation

The largest product of 3 contiguous digits is 9 * 8 * 6 = 432.

Example 2
Input

num = 77510373
k = 6
Output

0
Explanation

The digits have to be contiguous and 0 appears in every k-sized window, so we must return 0.
*/

#include "solution.hpp"
using namespace std;


class Solution {
    public:
    int solve(int num, int k) {
        vector<int> d;
        while(num){
            d.push_back(num%10);
            num/=10;
        }
        int ans=0;
        for(int i=0;i<=d.size()-k;i++){
            int p=1;
            for(int j=0;j<k;j++) p*=d[i+j];
            ans=max(p,ans);
        }
        return ans;
    }
};

