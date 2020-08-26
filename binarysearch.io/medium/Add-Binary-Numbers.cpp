#include "solution.hpp"
using namespace std;


class Solution {
    public:
    string solve(string a, string b) {
        string ans="";
        int carry=0;
        for (int i=a.size()-1, j=b.size()-1; i>=0||j>=0; i--,j--) {
                int m=(i>=0&&a[i]=='1');
                int n=(j>=0&&b[j]=='1');
                ans=to_string((m+n+carry)&1)+ans;
                carry=(m+n+carry)>>1;
        }
        return carry?'1'+ans:ans;
    }
};
