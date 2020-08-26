/*
Find the Minimum Number of Fibonacci Numbers Whose Sum Is K

Given the number k, return the minimum number of Fibonacci numbers whose sum is equal to k, whether a Fibonacci number could be used multiple times.

The Fibonacci numbers are defined as:

F1 = 1
F2 = 1
Fn = Fn-1 + Fn-2 , for n > 2.
It is guaranteed that for the given constraints we can always find such fibonacci numbers that sum k.
 

Example 1:

Input: k = 7
Output: 2 
Explanation: The Fibonacci numbers are: 1, 1, 2, 3, 5, 8, 13, ... 
For k = 7 we can use 2 + 5 = 7.
Example 2:

Input: k = 10
Output: 2 
Explanation: For k = 10 we can use 2 + 8 = 10.
Example 3:

Input: k = 19
Output: 3 
Explanation: For k = 19 we can use 1 + 5 + 13 = 19.
 

Constraints:

1 <= k <= 10^9
*/

class Solution {
public:
    int findMinFibonacciNumbers(int k) {
       int f1=0, f2=1;
        while(f2<=k){
            swap(f1,f2);
            f2+=f1;
        }
        // 19
        // f1 - f2 - k
        // 13 - 21 - 19
        // 5 - 8 - 6
        // 1 - 2 - 1
        return 1+(k==f1?0:findMinFibonacciNumbers(k-f1));
    }
};

class Solution2 {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> f;
        int i=3, n, ans=0;
        f.push_back(0);
        f.push_back(1);
        f.push_back(1);
        while(true){
            n=f[i-1]+f[i-2];
            if(n>k) break;
            f.push_back(n);
            i++;
        }
        int j=f.size()-1;
        while(k){
            ans+=k/f[j];
            k%=f[j];
            j--;
        }
        return ans;
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();