/*
Kth Smallest Element in a Sorted Matrix

Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.
Note:
You may assume k is always valid, 1 ≤ k ≤ n2.
*/

class Solution {
public:
    // similar to 668. Kth Smallest Number in Multiplication Table
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int rsz = matrix.size();
        int csz = matrix[0].size();
        int l=matrix[0][0],r=matrix[rsz-1][csz-1]+1,m;
        // binary search approach
        while(l<r){
            m=l+(r-l)/2;
            int cnt=0, j=rsz-1;
            for(int i=0;i<csz;i++){
                while(j>=0&&matrix[i][j]>m) j--;
                // calculate how many values are less than / equal to k
                cnt+=j+1;
            }
            // update the boundary and search again
            if(cnt>=k) r=m;
            else l=m+1;
        }
        return l;
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();