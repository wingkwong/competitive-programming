#include "solution.hpp"
using namespace std;


class Solution {
    public:
    bool solve(string s, string t) {
        int cnt[26]={0};
        for(char c:s) cnt[c-'a']++;
        for(char c:t) cnt[c-'a']++;
        for(int i=0;i<26;i++){
            if(cnt[i]&1) return false;
        }
        return true;
    }
};
