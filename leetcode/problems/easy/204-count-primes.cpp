/*
Count Primes

Count the number of prime numbers less than a non-negative number, n.

Example:

Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
*/

class Solution {
public:
    int countPrimes(int n) {
//     algorithm Sieve of Eratosthenes is
//     input: an integer n > 1.
//     output: all prime numbers from 2 through n.

//     let A be an array of Boolean values, indexed by integers 2 to n,
//     initially all set to true.
    
//     for i = 2, 3, 4, ..., not exceeding √n do
//         if A[i] is true
//             for j = i2, i2+i, i2+2i, i2+3i, ..., not exceeding n do
//                 A[j] := false

//     return all i such that A[i] is true.
        if(n<2) return 0;
        bool isPrime[n];
        int ans=0;
        for(int i=2;i<n;i++) isPrime[i]=true;
        for(int i=2;i*i<n;i++){
            if(isPrime[i]) {
                for(int j=i*i;j<n;j+=i){
                    isPrime[j] = false;
                }
            }
        }
        for(int i=2;i<n;i++) {
            if(isPrime[i]) ans++;
        }
        return ans;
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();