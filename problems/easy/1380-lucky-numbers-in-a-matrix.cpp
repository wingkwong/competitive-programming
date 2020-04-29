/*
Lucky Numbers in a Matrix

Given a m * n matrix of distinct numbers, return all lucky numbers in the matrix in any order.

A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.

Example 1:

Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
Output: [15]
Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column
Example 2:

Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
Output: [12]
Explanation: 12 is the only lucky number since it is the minimum in its row and the maximum in its column.
Example 3:

Input: matrix = [[7,8],[1,2]]
Output: [7]
 

Constraints:

m == mat.length
n == mat[i].length
1 <= n, m <= 50
1 <= matrix[i][j] <= 10^5.
All elements in the matrix are distinct.
*/

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int r = (int) matrix.size();
        int c = (int) matrix[0].size();
        vector<int> rr(r,INT_MAX);
        vector<int> cc(c,INT_MIN);
        vector<int> ans;
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                // find out and save the minimum of each row and maximum of each column in two lists.
                rr[i]=min(rr[i], matrix[i][j]);
                cc[j]=max(cc[j], matrix[i][j]);
            }
        }
        
        // scan through the whole matrix to identify the elements that satisfy the criteria
        for(int k : rr){
            if(find(cc.begin(),cc.end(),k)!=cc.end()) ans.push_back(k);
        }
        
        return ans;
    }
};

//             | min
// 3  7   8    | 3
// 9  11  13   | 9
// 15 16  17   | 15
// ---------------------
// 15 16  17 (max)