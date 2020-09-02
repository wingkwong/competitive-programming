#include "solution.hpp"
using namespace std;


class Solution {
    public:
    string solve(string s) {
        vector<char> vowels, consonants;
        for(char c:s) {
            if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') vowels.push_back(c);
            else consonants.push_back(c);
        }
        sort(vowels.begin(), vowels.end());
        sort(consonants.begin(), consonants.end());
        string ans;
        for(char c:vowels) ans+=c;
        for(char c:consonants) ans+=c;
        return ans;
    }
};
