/*
Check If N and Its Double Exist

Given an array arr of integers, check if there exists two integers N and M such that N is the double of M ( i.e. N = 2 * M).

More formally check if there exists two indices i and j such that :

i != j
0 <= i, j < arr.length
arr[i] == 2 * arr[j]
 

Example 1:

Input: arr = [10,2,5,3]
Output: true
Explanation: N = 10 is the double of M = 5,that is, 10 = 2 * 5.
Example 2:

Input: arr = [7,1,14,11]
Output: true
Explanation: N = 14 is the double of M = 7,that is, 14 = 2 * 7.
Example 3:

Input: arr = [3,1,7,11]
Output: false
Explanation: In this case does not exist N and M, such that N = 2 * M.
 

Constraints:

2 <= arr.length <= 500
-10^3 <= arr[i] <= 10^3
*/

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        set<int> s;
        for(int n:arr){
            // case 1: if target exists before the current index => s.count(2*n)
            // case 2: if target exists after the current index => s.count(n/2)
            // We need to add n%2==0 to avoid cases like n=7,m=3  (7/2->3..1)
            if(s.count(2*n)||(s.count(n/2)&&n%2==0)) return true;
            // inserting each value to a set
            s.insert(n);
        }
        return false;
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();