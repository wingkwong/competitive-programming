#include "solution.hpp"
using namespace std;


class Solution {
    public:
    int solve(int n) {
       string s = to_string(n);
       for(int i=0;i<s.size();i++){
           if(s[i]!='3'){
               s[i]='3';
               break;
           }
       }
       return stoi(s);
    }
};
