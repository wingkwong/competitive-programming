/*
Sum of Mutated Array Closest to Target

Given an integer array arr and a target value target, return the integer value such that when we change all the integers larger than value in the given array to be equal to value, the sum of the array gets as close as possible (in absolute difference) to target.

In case of a tie, return the minimum such integer.

Notice that the answer is not neccesarilly a number from arr.

 

Example 1:

Input: arr = [4,9,3], target = 10
Output: 3
Explanation: When using 3 arr converts to [3, 3, 3] which sums 9 and that's the optimal answer.
Example 2:

Input: arr = [2,3,5], target = 10
Output: 5
Example 3:

Input: arr = [60864,25176,27249,21296,20204], target = 56803
Output: 11361
 

Constraints:

1 <= arr.length <= 10^4
1 <= arr[i], target <= 10^5
*/

class Solution {
public:
    int helper(vector<int>& arr, int target, int mid){
        int sum=0;
        for(int a:arr) sum+=min(a,mid);
        return abs(sum-target);
    }
    
    int findBestValue(vector<int>& arr, int target) {
        // binary search approach
        int n=(int)arr.size();
        if(n==0) return 0;
        sort(arr.begin(),arr.end());
        int l=arr[0];
        int r=arr[n-1];
        while(l<r){
            int mid=l+(r-l)/2;
            int d1=helper(arr,target,mid);
            int d2=helper(arr,target,mid-1);
            if(d1>d2){
                r=mid-1;
            } else {
                l=mid+1;
            }
        }
        return l;
    }
};