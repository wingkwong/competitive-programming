/*
Prime Number of Set Bits in Binary Representation
https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/

Given two integers L and R, find the count of numbers in the range [L, R] (inclusive) having a prime number of set bits in their binary representation.

(Recall that the number of set bits an integer has is the number of 1s present when written in binary. For example, 21 written in binary is 10101 which has 3 set bits. Also, 1 is not a prime.)

Example 1:

Input: L = 6, R = 10
Output: 4
Explanation:
6 -> 110 (2 set bits, 2 is prime)
7 -> 111 (3 set bits, 3 is prime)
9 -> 1001 (2 set bits , 2 is prime)
10->1010 (2 set bits , 2 is prime)
Example 2:

Input: L = 10, R = 15
Output: 5
Explanation:
10 -> 1010 (2 set bits, 2 is prime)
11 -> 1011 (3 set bits, 3 is prime)
12 -> 1100 (2 set bits, 2 is prime)
13 -> 1101 (3 set bits, 3 is prime)
14 -> 1110 (3 set bits, 3 is prime)
15 -> 1111 (4 set bits, 4 is not prime)
Note:

L, R will be integers L <= R in the range [1, 10^6].
R - L will be at most 10000.
*/

class Solution {
public:
    vector<bool> seiveOfEratosthenes(const int n) {
      assert(n >= 2 && "N must be greater or equal to 2");
      vector<bool> isPrime(n + 1, true);
      isPrime[0] = isPrime[1] = 0;
      for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
          for (int j = i * i; j <= n; j += i) {
            isPrime[j] = false;
          }
        }
      }
      return isPrime;
    }
    
    int countPrimeSetBits(int L, int R) {
        vector<bool> isPrime = seiveOfEratosthenes(20);
        int ans = 0;
        for(int i = L; i <= R; i++) {
            ans += isPrime[__builtin_popcount(i)];
        }
        return ans;
    }
};

class Solution {
public:
    bool isPrime(long long n) {
      for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
      }
      return true;
    }
    
    int countPrimeSetBits(int L, int R) {
        int ans = 0;
        for(int i = L; i <= R; i++) {
            int k = __builtin_popcount(i);
            if(k == 1) continue;
            ans += isPrime(k);
        }
        return ans;
    }
};