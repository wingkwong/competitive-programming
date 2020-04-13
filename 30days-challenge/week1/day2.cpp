/*
Happy Number

Write an algorithm to determine if a number n is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Return True if n is a happy number, and False if not.

Example: 

Input: 19
Output: true
Explanation: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/

class Solution {
public:
    bool isHappy(int n) {
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL);
        if(n==1||n==7) return true;
        int sum=n,x=n;
        while(sum>9){
            sum=0;
            while(x>0){
                int d=x%10;
                sum+=d*d;
                x/=10;
            }
            if(sum==1) return true;
            x=sum;
        }
        if(sum==7) return true;
        return false;
    }
};