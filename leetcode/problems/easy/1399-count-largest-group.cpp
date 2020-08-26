/*
Count Largest Group

Given an integer n. Each number from 1 to n is grouped according to the sum of its digits. 

Return how many groups have the largest size.

 

Example 1:

Input: n = 13
Output: 4
Explanation: There are 9 groups in total, they are grouped according sum of its digits of numbers from 1 to 13:
[1,10], [2,11], [3,12], [4,13], [5], [6], [7], [8], [9]. There are 4 groups with largest size.
Example 2:

Input: n = 2
Output: 2
Explanation: There are 2 groups [1], [2] of size 1.
Example 3:

Input: n = 15
Output: 6
Example 4:

Input: n = 24
Output: 5
 

Constraints:

1 <= n <= 10^4
*/

class Solution {
public:
    int countLargestGroup(int n) {
        int a[10000]={0};
        int ans=0;
        for(int i=1;i<=n;i++){
            a[sumDigit(i)-1]++;
        }
        int sz = sizeof(a) / sizeof(a[0]); 
        int max = *max_element(a,a+sz);
        for(int k : a){
            if(k==max) ans++;
        }
        return ans;
    }
private:
    int sumDigit(int i){
        if(i<10) return i;
        int sum=0;
        while(i){
            sum+=i%10;
            i/=10;
        }
        return sum;
    }
};