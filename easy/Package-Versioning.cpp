#include "solution.hpp"
using namespace std;


class Solution {
    public:
    bool solve(string older, string newer) {
        istringstream is1(newer);
        istringstream is2(older);
        int num1=0, num2=0;
        char c;
        while(bool(is1>>num1)+bool(is2>>num2)) {
            if(num1>num2) return true;
            if(num1<num2) return false;
            is1 >> c; is2 >> c;
            num1=num2=0;
        }
        return 0;
    }
};
