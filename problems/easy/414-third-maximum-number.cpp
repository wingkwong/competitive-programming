/*
Third Maximum Number

Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).

Example 1:
Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.
Example 2:
Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
Example 3:
Input: [2, 2, 3, 1]

Output: 1

Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.
*/

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        for(int num:nums) s.insert(num);
        return s.size() < 3 ? 
            // return the maximum number if the third maximum number does not exist
            *max_element(s.begin(),s.end()) :
            // return the third maximum number in this array
            *next(s.begin(),s.size()-3);
    }
};

// Failed on below test case
// Input:
// [3,3,4,3,4,3,0,3,3]
// Output:
// 4
// Expected:
// 0
class Solution2 {
public:
    int thirdMax(vector<int>& nums) {
        int a1=NULL,a2=NULL,a3=NULL;
        for(int num: nums){
            if(num==a1||num==a2||num==a3) continue;
            if(a1==NULL||num>a1){
                a3=a2;
                a2=a1;
                a1=num;
            } else if(a2==NULL||num>a2){
                a3=a2;
                a2=num;
            } else if(a3==NULL||num>a3){
                a3=num;
            }
        }
        return a3==NULL?a1:a3;
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();