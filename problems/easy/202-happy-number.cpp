/*
Happy Number

Write an algorithm to determine if a number n is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Return True if n is a happy number, and False if not.

Example: 

Input: 19
Output: true
Explanation: 
1**2 + 9**2 = 82
8**2 + 2**2 = 68
6**2 + 8**2 = 100
1**2 + 0**2 + 0**2 = 1
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


// Using Floyd Cycle Detection Algorithm 
// Ref: https://en.wikipedia.org/wiki/Cycle_detection
class Solution2 {
public:
    bool isHappy(int n) {
        int slow, fast = n;
        do {
            slow=digitSquareSum(slow);
            fast=digitSquareSum(fast);
            fast=digitSquareSum(fast);
            // input: 19
            // slow - 19 - 82
            // fast - 19 - 100 - 1 (return)
            if(slow==1||fast==1) return true;
        } while(slow!=fast);
        return false;
    }
private:
    int digitSquareSum(int n){
        int sum=0, d;
        while(n){
            d=n%10;
            sum+=d*d;
            n/=10;
        }
        return sum;
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();