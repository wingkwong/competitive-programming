/*
Reconstruct Original Digits from English
https://leetcode.com/problems/reconstruct-original-digits-from-english/

Given a non-empty string containing an out-of-order English representation of digits 0-9, output the digits in ascending order.

Note:
Input contains only lowercase English letters.
Input is guaranteed to be valid and can be transformed to its original digits. That means invalid inputs such as "abc" or "zerone" are not permitted.
Input length is less than 50,000.
Example 1:
Input: "owoztneoer"

Output: "012"
Example 2:
Input: "fviefuro"

Output: "45"
*/

class Solution {
public:
    string originalDigits(string s) {
  		// e: 0 1 3 5 7 8 9
		// f: 4 5
		// g: 8
		// h: 3 8
		// i: 5 6 8 9
		// n: 1 7 9
		// o: 0 1 2 4
		// r: 0 3 4
		// s: 6 7
		// t: 2 3 8
		// u: 4
		// v: 5 7
		// w: 2
		// x: 6
		// z: 0
        vector<int> cnt(26, 0), num(10, 0);
        for (auto c: s) cnt[c - 'a'] ++;	
        num[0] = cnt['z' - 'a'];
        num[2] = cnt['w' - 'a'];
        num[4] = cnt['u' - 'a'];
        num[8] = cnt['g' - 'a'];
        num[5] = cnt['f' - 'a'] - num[4];
        num[7] = cnt['v' - 'a'] - num[5];
        num[3] = cnt['t' - 'a'] - num[2] - num[8];
        num[6] = cnt['s' - 'a'] - num[7];
        num[1] = cnt['o' - 'a'] - num[0] - num[2] - num[4];
        num[9] = cnt['i' - 'a'] - num[5] - num[6] - num[8];
        string ans = "";
        for (int i = 0; i < 10; i ++) ans.append(num[i], '0' + i);
        return ans;
    }
};