/*
Excel Sheet Column Title    

Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
    ...
Example 1:

Input: 1
Output: "A"
Example 2:

Input: 28
Output: "AB"
Example 3:

Input: 701
Output: "ZY"
*/

class Solution {
public:
    string convertToTitle(int n) {
        if(--n<26) return string(1,n+65);
        return convertToTitle(n/26)+string(1,n%26+65);
    }
};