/*
Pancake Sorting

Given an array A, we can perform a pancake flip: We choose some positive integer k <= A.length, then reverse the order of the first k elements of A.  We want to perform zero or more pancake flips (doing them one after another in succession) to sort the array A.

Return the k-values corresponding to a sequence of pancake flips that sort A.  Any valid answer that sorts the array within 10 * A.length flips will be judged as correct.

Example 1:

Input: [3,2,4,1]
Output: [4,2,4,3]
Explanation: 
We perform 4 pancake flips, with k values 4, 2, 4, and 3.
Starting state: A = [3, 2, 4, 1]
After 1st flip (k=4): A = [1, 4, 2, 3]
After 2nd flip (k=2): A = [4, 1, 2, 3]
After 3rd flip (k=4): A = [3, 2, 1, 4]
After 4th flip (k=3): A = [1, 2, 3, 4], which is sorted. 
Example 2:

Input: [1,2,3]
Output: []
Explanation: The input is already sorted, so there is no need to flip anything.
Note that other answers, such as [3, 3], would also be accepted.
 

Note:

1 <= A.length <= 100
A[i] is a permutation of [1, 2, ..., A.length]
*/

class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        int sz=(int)A.size();
        vector<int> ans;
        for(int i=0;i<sz;i++){
            auto mp=max_element(A.begin(),A.end()-i);
            ans.push_back(mp-A.begin()+1);
            ans.push_back(sz-i);
            reverse(A.begin(),mp+1);
            reverse(A.begin(),A.end()-i);
        }
        return ans;
    }
};

// Test case: 3,2,4,1
// -------------
// i:0;n=4;
// 3 2 [4] 1  // find the max number A[mp] from 0..n-1-i / A[2]=4 is the max from 0..3
// 4 2 3 1    // reverse 0..mp+1 numbers. [ 3 2 4 ] -> [ 4 2 3 ]. 1 keeps at the same place
// 1 3 2 4    // reverse 0..n-1-i. [ 4 2 3 1 ] to [ 1 3 2 4 ]
// --------------
// i:1;n=4;
// 1 3 2 4   // now the largest value is located at the end, 4 is fixed here and find the max number from 0..n-1-i
// 3 1 2 4   // the max number is 3, reverse the first two numbers [ 1 3 ] -> [ 3 1 ] while [ 2 4 ] keeps at the same place
// 2 1 3 4   // reverse 0..n-1-i [ 3 1 2 4 ] -> [ 2 1 3 4 ]
// --------------
// i:2;n=4;
// 2 1 3 4   // similarly, perform the same action
// 2 1 3 4   // the max number is located index 0, no action is made here 
// 1 2 3 4   // reverse 0..n-1-i [ 2 1 3 4 ] -> [ 1 2 3 4 ]
// --------------
// i:3;n=4;
// 1 2 3 4   // already sorted. no action is performed
// 1 2 3 4 
// 1 2 3 4 
// --------------