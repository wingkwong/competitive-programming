#include "solution.hpp"
using namespace std;


class Solution {
    public:
    int solve(string s) {
        unordered_map<int,int> m;
        int ans=-1;
        for(int i=0;i<s.size();i++){
            if(m[s[i]]) return i;
            m[s[i]]++;
        }
        return ans;
    }
};
