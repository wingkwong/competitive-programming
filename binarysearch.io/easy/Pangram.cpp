#include "solution.hpp"
using namespace std;


class Solution {
    public:
    bool solve(string s) {
       int cnt[26]={0};
       for(char c:s){
           if(!isalpha(c)) continue;
           c=tolower(c);
           cnt[c-'a']++;
       }
       for(int i=0;i<26;i++){
           if(cnt[i]==0) return false;
       }
       return true;
    }
};
