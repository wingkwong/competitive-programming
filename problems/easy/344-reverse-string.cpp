/*
Reverse String

Write a function that reverses a string. The input string is given as an array of characters char[].

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

You may assume all the characters consist of printable ascii characters.

*/

class Solution {
public:
    void reverseString(vector<char>& s) {
        int sz=s.size();
        for(int i=0;i<sz/2;i++) swap(s[i],s[sz-i-1]);
    }
};

class Solution2 {
public:
    void reverseString(vector<char>& s) {
       reverse(s.begin(), s.end());
    }
};
static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

