/*
Plus One

Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& d) {
        int n=(int)d.size();
        int c=1;
        for(int i=n-1;i>=0;i--){
            if(d[i]!=9){
                // add 1 to value at the current index
                d[i]+=1;
                return d;
            }
            
            if(i==0&&d[i]==9) {
                // reach the end
                // [9,9,9] -> [1,0,0,0]
                d[i]=0;
                d.insert(d.begin(),1);
            } else {
                // make it zero
                d[i]=0;
            }
        }
        return d;
    }
};