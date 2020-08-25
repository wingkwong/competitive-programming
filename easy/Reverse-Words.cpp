#include "solution.hpp"
using namespace std;


class Solution {
    public:
    string solve(string sentence) {
        istringstream iss(sentence);
        string ans, s;
        while(iss>>s) ans=s+(ans.size()==0?"":" ")+ans;
        return ans;
    }
};
