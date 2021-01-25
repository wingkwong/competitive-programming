/*
Decode XORed Permutation
https://leetcode.com/problems/decode-xored-permutation/

There is an integer array perm that is a permutation of the first n positive integers, where n is always odd.

It was encoded into another integer array encoded of length n - 1, such that encoded[i] = perm[i] XOR perm[i + 1]. For example, if perm = [1,3,2], then encoded = [2,1].

Given the encoded array, return the original array perm. It is guaranteed that the answer exists and is unique.

 

Example 1:

Input: encoded = [3,1]
Output: [1,2,3]
Explanation: If perm = [1,2,3], then encoded = [1 XOR 2,2 XOR 3] = [3,1]
Example 2:

Input: encoded = [6,5,4,6]
Output: [2,4,1,5,3]
 

Constraints:

3 <= n < 105
n is odd.
encoded.length == n - 1
*/

class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        vector<int> ans;
        int n = (int) encoded.size() + 1, x = 0, k = 0;
        for(int i = 1; i <= n; i++) x ^= i;
        // find (a ^ b) ^ (c ^ d)
        for(int i = 0; i < n - 1; i += 2) k ^= encoded[i];
        // find the last element first 
    	// (a ^ b ^ c ^ d ^ e) ^ ((a ^ b) ^ (c ^ d))
    	// = e 
        int j = x ^ k;
        ans.push_back(j);
        // then find d, c, b, a ...
        for(int i = n - 2; i >= 0; i--) {
            j ^= encoded[i];
            ans.push_back(j);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};