/*
Kth Missing Positive Number

Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Find the kth positive integer that is missing from this array.

Example 1:

Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
Example 2:

Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.
*/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        for(int i=1;;i++){
            // find if the number exists, decrease k by 1 if not
            if(find(arr.begin(),arr.end(),i)==arr.end()) k--;
            // if k==0, i would be the ans
            if(k==0) return i;
        }
    }
};

class Solution2 {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // binary search approach
        int n=arr.size();
        if(n==0||arr[0]>k)return k;
        if(arr[n-1]<n+k) return n+k;
        int l=0;
        int r=n-1;
        while(l<r){
            int mid=l+(r-l)/2;
            if(arr[mid]-(mid+1)<k) l=mid+1;
            else r=mid;
        }
        return k+l;
    }
};