/*
Sequential Digits

An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

 

Example 1:

Input: low = 100, high = 300
Output: [123,234]
Example 2:

Input: low = 1000, high = 13000
Output: [1234,2345,3456,4567,5678,6789,12345]
 

Constraints:

10 <= low <= high <= 10^9
*/

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> s;
        for(int i=1;i<=9;i++){
            int d=0;
            for(int j=i;j<=9;j++){
                d=d*10+j;
                s.push_back(d);
            }
        }
        sort(s.begin(), s.end());
        vector<int> ans;
        auto l = upper_bound(s.begin(), s.end(), low-1);
        auto r = lower_bound(s.begin(), s.end(), high+1);
        return vector<int>(l,r);
    }
};