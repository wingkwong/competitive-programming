#include "solution.hpp"
using namespace std;


class Solution {
    public:
    int solve(int n) {
        string s = to_string(n);
        if(n>0){
            for(int i=0;i<s.size();i++){
                if(s[i]<'5') {
                    s=s.substr(0,i)+"5"+s.substr(i);
                    return stoi(s);
                }
            }
        } else{
            for(int i=1;i<s.size();i++){
                if(s[i]>'5') {
                    s=s.substr(0,i)+"5"+s.substr(i);
                    return stoi(s);
                }
            }
        }
        return stoi(s+"5");
    }
};
