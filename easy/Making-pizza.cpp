#include "solution.hpp"
using namespace std;


class Solution {
    public:
    int solve(string s) {
        int p=0,i=0,z=0,z1=0,z2=0,a=0;
        for(char c:s){
            if(c=='p') p++;
            else if(c=='i') i++;
            else if(c=='z') {
                if(z) z1++;
                else z2++;
                z=!z;
            }
            else if(c=='a') a++;
        }
        return min({p,i,z1,z2,a});
    }
};
