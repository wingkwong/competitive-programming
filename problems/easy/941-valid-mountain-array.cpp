/*
Valid Mountain Array

Given an array A of integers, return true if and only if it is a valid mountain array.

Recall that A is a mountain array if and only if:

A.length >= 3
There exists some i with 0 < i < A.length - 1 such that:
A[0] < A[1] < ... A[i-1] < A[i]
A[i] > A[i+1] > ... > A[A.length - 1]

Example 1:

Input: [2,1]
Output: false
Example 2:

Input: [3,5,5]
Output: false
Example 3:

Input: [0,3,2,1]
Output: true
 

Note:

0 <= A.length <= 10000
0 <= A[i] <= 10000 
 
*/

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int sz=A.size(), i=0,j=sz-1;
        // going up from left to right
        while(i+1<sz&&A[i]<A[i+1]) i++;
        // going up from right to left
        while(j>0&&A[j-1]>A[j]) j--;
        // peak cannot be the first or the last
        // i and j should meet at the same point
        return i>=0 &&i==j&&j<sz-1;
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();