/*
Valid Perfect Square

Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Output: true
Example 2:

Input: 14
Output: false
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        // binary search approach
        if(num==1) return 1;
        long l=1,r=num,m;
        while(l<r){
            m=l+(r-l)/2;
            if(m*m==num) return true;
            if(m*m>num) r=m;
            else l=m+1;
        }
        return false;
    }
};

class Solution2 {
public:
    bool isPerfectSquare(int num) {
        // Netwon's method
        // Ref: https://en.wikipedia.org/wiki/Integer_square_root
        long x = num;
        while(x*x>num) x=(x+num/x)/2;
        return x*x==num;
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();