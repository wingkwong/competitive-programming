#include "solution.hpp"
using namespace std;


class Solution {
    public:
    int solve(string text, string word0, string word1) {
        istringstream is(text);
        string s;
        int i=-1, j=-1, idx=0, ans=INT_MAX;
        while(is>>s){
            if(s==word0) i=idx;
            else if(s==word1) j=idx;
            if(i!=-1&&j!=-1) ans=min(ans,abs(i-j)-1);
            idx++;
        }
        if(i==-1||j==-1) return -1;
        else return ans;
    }
};
