/*
Replace Elements with Greatest Element on Right Side

Given an array arr, replace every element in that array with the greatest element among the elements to its right, and replace the last element with -1.

After doing so, return the array.

 

Example 1:

Input: arr = [17,18,5,4,6,1]
Output: [18,6,6,6,1,-1]
 

Constraints:

1 <= arr.length <= 10^4
1 <= arr[i] <= 10^5
*/

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int sz=arr.size();
        for(int i=0;i<sz-1;i++){
            int max=0;
            for(int j=i+1;j<=sz-1;j++){
                if(arr[j]>max)max=arr[j];
            }
            arr[i]=max;
        }
        arr[sz-1]=-1;
        return arr;
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();