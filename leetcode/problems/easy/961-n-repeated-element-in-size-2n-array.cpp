/*
N-Repeated Element in Size 2N Array

In a array A of size 2N, there are N+1 unique elements, and exactly one of these elements is repeated N times.

Return the element repeated N times.

Example 1:

Input: [1,2,3,3]
Output: 3
Example 2:

Input: [2,1,2,5,3,2]
Output: 2
Example 3:

Input: [5,1,5,2,5,3,5,4]
Output: 5
 

Note:

4 <= A.length <= 10000
0 <= A[i] < 10000
A.length is even
*/

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_set<int> s;
        for(int i : A) {
            if(s.count(i)) return i;
            else s.insert(i);
        }
        return -1;
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();
