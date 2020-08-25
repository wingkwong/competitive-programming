#include "solution.hpp"
using namespace std;


class Solution {
    public:
    bool solve(string s) {
        int n = s.size();
        if(n==0) return true;
        int i=0, j=n-1;
        while(i<j){
            if(s[i]==s[j]) i++, j--; 
            else return false;
        }
        return true;
    }
};
