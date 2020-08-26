/*
PRIME1 - Prime Generator
https://www.spoj.com/problems/PRIME1/
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 

int main()
{
    FAST_INP;
    int t;
    int m,n;
    bool prime;
    cin >> t;
    while(t--){
        cin >> m >> n;
        // from m to n
        for(int i=m;i<=n;i++){
            // reset prime 
            prime=true;
            // from 2 to sqrt(m)
            for(int j=2;j*j<=i;j++){
                if(i%j==0) {
                    // if it can be divisible, i is not a prime number
                    prime=false;
                    break;
                }
            }
            // for m < 4, the above logic will be skipped 
            // 1,2,3 will be directly considered as a prime number 
            // while 1 is not a prime number
            // add i!=1 to bypass this pass
            if(prime&&i!=1) {
                cout << i << "\n";
            }
        }
    }
    return 0;
}

// Sieve of Eratosthenes approach may cause TLE if n is 1000000000
// -----------------------------

// int main()  
// { 
    // FAST_INP;
    // int t;
    // int m,n;
    // cin >> t;
    // while(t--){
    //     cin >> m >> n;
//         //     algorithm Sieve of Eratosthenes is
//         //     input: an integer n > 1.
//         //     output: all prime numbers from 2 through n.

//         //     let A be an array of Boolean values, indexed by integers 2 to n,
//         //     initially all set to true.
            
//         //     for i = 2, 3, 4, ..., not exceeding √n do
//         //         if A[i] is true
//         //             for j = i2, i2+i, i2+2i, i2+3i, ..., not exceeding n do
//         //                 A[j] := false

//         //     return all i such that A[i] is true.
//         if(n<2) {
//             cout << 0 << "\n";
//         } else {
//             bool isPrime[n];
//             memset(isPrime,true,sizeof(isPrime));
//             isPrime[0]=isPrime[1]=false;
            
//             for(int i=2;i*i<n;i++){
//                 if(isPrime[i]){
//                     for(int j=i*i;j<n;j+=i){
//                         isPrime[j]=false;
//                     }
//                 }
//             }
//             for(int i=m;i<=n;i++){
//                 if(isPrime[i]){
//                     cout << i << "\n";
//                 }
//             }
//         }
//         cout << "\n";
//     }
//     return 0;
// } 