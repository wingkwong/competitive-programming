#include "solution.hpp"
using namespace std;


class Solution {
    public:
    string solve(string s) {
        istringstream iss(s);
        string ss, ans;
        while(iss>>ss) {
            if(ss=="and") continue;
            ans+=toupper(ss[0]);
        }
        return ans;
    }
};
