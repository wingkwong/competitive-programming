#include "solution.hpp"
using namespace std;


class Solution {
    public:
    int f[35] = {0};
    int fib(int n){
        if(n==0) return 0;
        if(n==1||n==2) return (f[n]=1);
        if(f[n]) return f[n];
        int k = (n&1)?(n+1)/2:n/2;
        f[n]=(n&1)?(fib(k)*fib(k)+fib(k-1)*fib(k-1)):(2*fib(k-1)+fib(k))*fib(k);
        return f[n];
    }
    
    int solve(int n) {
        return fib(n);
    }
};
