/*
Flipped-Matrix
https://binarysearch.io/problems/Flipped-Matrix

You are given a two-dimensional integer matrix containing 0 and 1. For any row or column in the matrix you can toggle all the bits such that all the 1s become 0 and all the 0s become 1.

Given you can make any number of these operations, and that we treat each row as a binary number, return the largest sum that can be made of these numbers.

Constraints

n, m ≤ 30 where n and m are the number of rows and columns in matrix.
Example 1
Input

matrix = [
    [0, 0, 1],
    [0, 0, 0]
]
Output

13
Explanation

If we flip both rows we get

[1, 1, 0]
[1, 1, 1]
In binary these are 6 and 7 and their sum is 13.
*/

#include "solution.hpp"
using namespace std;


class Solution {
    public:
    int solve(vector<vector<int>>& matrix) {
        /*
        To achieve the maximum sum, the leftmost column must be all 1s. 
        Therefore, we check if matrix[i][0] is 0 first. If so, flip the whole row simply by using xor.
        We need to store how many 1s in each column. The number of 1s in the first column must be the number of row. Hence, v[0]=m;
        Then, for each column starting from the second one, we check if the number of 0s is greater than that of 1s / 2. 
        If so, that means we need to flip the whole column. 
        However, we don't actually need to flip it because we just wanna know the number of 1s. 
        Therefore, it is either zero (flip all 0s to 1s), or m-zero (no need to flip).
        The last part is to calculate the sum. Starting from the rightmost digit, we just need to multiple by 1,2,4,8... as this is a binary number.
        */
        int m=matrix.size(), n=matrix[0].size(), ans=0;
        for(int i=0;i<m;i++) {
            if(matrix[i][0]==0) {
                for(int j=0;j<n;j++) {
                    matrix[i][j]^=1;
                }
            }
        }
        vector<int> v(n,0);
        v[0]=m;
        for(int j=1;j<n;j++) { 
            int cnt=0, zero=0;
            for(int i=0;i<m;i++)zero+=matrix[i][j]==0;
            if(zero>(m/2)) v[j]=zero;
            else v[j]=m-zero;
        }
        int p=1;
        for(int i=v.size()-1;i>=0;i--){
            ans+=p*v[i];
            p*=2;
        }
        return ans;
    }
};