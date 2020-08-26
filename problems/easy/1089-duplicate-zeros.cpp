/*
Duplicate Zeros

Given a fixed length array arr of integers, duplicate each occurrence of zero, shifting the remaining elements to the right.

Note that elements beyond the length of the original array are not written.

Do the above modifications to the input array in place, do not return anything from your function.

 

Example 1:

Input: [1,0,2,3,0,4,5,0]
Output: null
Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]
Example 2:

Input: [1,2,3]
Output: null
Explanation: After calling your function, the input array is modified to: [1,2,3]
 

Note:

1 <= arr.length <= 10000
0 <= arr[i] <= 9
*/

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int k=0;
        int sz=arr.size()-1;

        for(int i=0;i<=sz-k;i++){
            if(arr[i]==0){
                // edge case
                if(i==sz-k){
                    arr[sz]=0;
                    sz--;
                    break;
                }
                k++;
            }
        }

        int r=sz-k;
        for(int i=r;i>=0;i--){
            if(arr[i]==0){
                arr[i+k]=0;
                k--;
                arr[i+k]=0;
            } else {
                arr[i+k] = arr[i];
            }
        }
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();