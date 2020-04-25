/*
Sort Array By Parity

Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.

You may return any answer array that satisfies this condition.

Example 1:

Input: [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
 

Note:

1 <= A.length <= 5000
0 <= A[i] <= 5000
*/

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> ans;
        for(int k : A) {
            // if even, insert it to the front
            if(k%2==0) ans.insert(ans.begin(),1,k);
            // if odd, insert it to the back
            else ans.push_back(k);
        }
        return ans;
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();