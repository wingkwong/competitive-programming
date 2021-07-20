/*
Three Equal Parts
https://leetcode.com/problems/three-equal-parts/

You are given an array arr which consists of only zeros and ones, divide the array into three non-empty parts such that all of these parts represent the same binary value.

If it is possible, return any [i, j] with i + 1 < j, such that:

arr[0], arr[1], ..., arr[i] is the first part,
arr[i + 1], arr[i + 2], ..., arr[j - 1] is the second part, and
arr[j], arr[j + 1], ..., arr[arr.length - 1] is the third part.
All three parts have equal binary values.
If it is not possible, return [-1, -1].

Note that the entire part is used when considering what binary value it represents. For example, [1,1,0] represents 6 in decimal, not 3. Also, leading zeros are allowed, so [0,1,1] and [1,1] represent the same value.

 

Example 1:

Input: arr = [1,0,1,0,1]
Output: [0,3]
Example 2:

Input: arr = [1,1,0,1,1]
Output: [-1,-1]
Example 3:

Input: arr = [1,1,0,0,1]
Output: [0,2]
 

Constraints:

3 <= arr.length <= 3 * 104
arr[i] is 0 or 1
*/

class Solution {
public:
    int find_first_one(vector<int>& arr, int target) {
        int cnt = 0;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] == 1) cnt++;
            if(cnt == target) return i;
        }
        return -1;
    }
    
    vector<int> threeEqualParts(vector<int>& arr) {
        int one = count(arr.begin(), arr.end(), 1);
        if(one % 3 != 0) return vector<int>{-1, -1};
        int one_per_part = one / 3;
        if(one_per_part == 0) return vector<int>{0, (int)arr.size() - 1};
        int l = find_first_one(arr, 1);
        int m = find_first_one(arr, one_per_part + 1);
        int r = find_first_one(arr, 2 * one_per_part + 1);
        while(r < arr.size()) {
            if(arr[l] == arr[m] && arr[m] == arr[r]) l++, m++, r++;
            else return vector<int>{-1, -1};
        }
        return vector<int>{l - 1, m};
    }
};