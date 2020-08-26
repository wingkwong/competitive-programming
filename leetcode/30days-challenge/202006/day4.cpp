/*
Reverse String

Write a function that reverses a string. The input string is given as an array of characters char[].

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

You may assume all the characters consist of printable ascii characters.

Example 1:

Input: ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
*/

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=(int)s.size();
        for(int i=0;i<n/2;i++){
            swap(s[i],s[n-i-1]);
            // -------------OR----------------
            // char c=s[i];
            // s[i]=s[n-i-1];
            // s[n-i-1]=c;
        }
    }
};