/*
Count Sorted Vowel Strings
https://leetcode.com/problems/count-sorted-vowel-strings/

Given an integer n, return the number of strings of length n that consist only of vowels (a, e, i, o, u) and are lexicographically sorted.

A string s is lexicographically sorted if for all valid i, s[i] is the same as or comes before s[i+1] in the alphabet.

 

Example 1:

Input: n = 1
Output: 5
Explanation: The 5 sorted strings that consist of vowels only are ["a","e","i","o","u"].
Example 2:

Input: n = 2
Output: 15
Explanation: The 15 sorted strings that consist of vowels only are
["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo","ou","uu"].
Note that "ea" is not a valid string since 'e' comes after 'a' in the alphabet.
Example 3:

Input: n = 33
Output: 66045
 

Constraints:

1 <= n <= 50 
*/

// AC - 0 ms
class Solution {
public:
    int countVowelStrings(int n) {
        // math (combinatorics)
        // n = 1 -> 5 slots - pick 4
        // n = 2 -> 6 slots - pick 4
        // ...
        // n + 4 choose 4
        // (n + 4) * (n + 3) * (n + 2) * (n + 1) / 4!
        return (n + 4) * (n + 3) * (n + 2) * (n + 1) / 24;
    }
};

// AC - 0 ms
class Solution2 {
public:
    int countVowelStrings(int n) {
        int a, e, i, o, u;
        a = e = i = o = u = 1;
        while(--n > 0) {
            a = a + e + i + o + u;
            e = e + i + o + u;
            i = i + o + u;
            o = o + u;
            u = u;
        }
        return a + e + i + o + u;
    }
};

// AC - 0 ms
class Solution3 {
public:
    int countVowelStrings(int n) {
        // pattern: 
        // 1 + 1 + 1 + 1 + 1 = 5
        // 1 + 2 + 3 + 4 + 5 = 15
        // 1 + 3 + 6 + 10 + 15 = 35
        // 1 + 4 + 10 + 20 + 35 = 70
        if(n == 1) return 5;
        int dp[5], ans;
        for(int i = 0; i < 5; i++) dp[i] = 1;
        for(int i = 2; i <= n; i++) {
            ans = 1;
            for( int j = 1; j < 5; j++) {
                dp[j] += dp[j - 1] , ans += dp[j];
            }
        }
        return ans;
    }
};