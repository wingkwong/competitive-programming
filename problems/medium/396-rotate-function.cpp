/*
Rotate Function

Given an array of integers A and let n to be its length.

Assume Bk to be an array obtained by rotating the array A k positions clock-wise, we define a "rotation function" F on A as follow:

F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n-1) * Bk[n-1].

Calculate the maximum value of F(0), F(1), ..., F(n-1).

Note:
n is guaranteed to be less than 105.

Example:

A = [4, 3, 2, 6]

F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26

So the maximum value of F(0), F(1), F(2), F(3) is F(3) = 26.
*/

// AC
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int sz = (int)A.size();
        if(!sz) return 0;
        long sum=0,cur=0,m=LONG_MIN;
        for(int i=0;i<sz;i++){
            sum+=A[i];
            cur+=A[i]*i;
        }
        // The diff between two rotations:
        // F(k) = F(k - 1) + ( sum(A) - A.size() * A(the last element in A after rotate k - 1 positions.))
        for(int i=sz-1;i>=0;i--){
            // long type for case: [2147483647,2147483647]
            cur+=sum-((long)A[i]*sz);
            m=max(m,cur);
        }
        return m;
    }
};
static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

// Time Limit Exceed
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int sz = (int)A.size();
        if(!sz) return 0;
        int m=INT_MIN;
        for(int i=0;i<sz;i++){
            int sum=0;
            for(int j=0;j<sz;j++){
                sum+=A[j]*j;
            }
            m=max(m,sum);
            rotate(A.begin(),A.begin()+1,A.end());
        }
        return m;
    }
};