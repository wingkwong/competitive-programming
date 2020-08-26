#include "solution.hpp"
using namespace std;


class Solution {
    public:
    int solve(int n) {
        int two=2,ans=0; 
        int tmp=n; 
        // (n/2^i)*2^(i-1)+ n%(2^i)-(2^(i-1)-1)
        // iff n%(2^i)>=(2^(i-1)-1)
        while(tmp){ 
            ans+=(n/two)*(two>>1); 
            if((n&(two-1))>(two>>1)-1) ans+=(n&(two-1))-(two>>1)+1; 
            two<<=1, tmp>>=1; 
        } 
        return ans; 
    }
};



class Solution2 {
    public:
    int solve(int n) {
        int ans=0; 
        do {
            ans+=__builtin_popcount(n);
        } while (--n);
            
        return ans; 
    }
};
