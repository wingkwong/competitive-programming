#include "solution.hpp"
using namespace std;


class Solution {
    public:
    string solve(vector<string>& words) {
       int mxLen=0;
       for(string w:words) mxLen=max(mxLen, (int)w.length());
       string x(mxLen+4, '*'), ans="";
       ans += x;
       ans += "\n";
       for(string w:words) {
           ans += "* ";
           ans += w;
           string space(mxLen-w.length(), ' ');
           ans += space;
           ans += " *";
           ans += "\n";
       }
       ans += x;
       return ans;
    }
};
