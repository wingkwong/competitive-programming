#include "solution.hpp"
using namespace std;


class Solution {
    public:
    vector<int> solve(int n) {
        vector<int> prime(n+1,1), ans;
        // seive
        for(int p=2; p*p<=n; p++) { 
            if(prime[p]) { 
                for(int i=p*2;i<=n;i+=p) 
                    prime[i]=0;
            } 
        } 
        // check if it is prime
        for (int p=2; p<=n; p++) 
           if (prime[p]) ans.push_back(p);
        return ans;
    }
};
