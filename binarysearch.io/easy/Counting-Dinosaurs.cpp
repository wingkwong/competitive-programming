#include "solution.hpp"
using namespace std;


class Solution {
    public:
    int solve(string animals, string dinosaurs) {
        unordered_set<char> s;
        int ans=0;
        for(char c: dinosaurs) s.insert(c);
        for(char c: animals) {
            if(s.find(c)!=s.end()){
                ans++;
            }
        }
        return ans;
    }
};
