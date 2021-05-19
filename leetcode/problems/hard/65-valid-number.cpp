/*
Valid Number
https://leetcode.com/problems/valid-number/

A valid number can be split up into these components (in order):

A decimal number or an integer.
(Optional) An 'e' or 'E', followed by an integer.
A decimal number can be split up into these components (in order):

(Optional) A sign character (either '+' or '-').
One of the following formats:
At least one digit, followed by a dot '.'.
At least one digit, followed by a dot '.', followed by at least one digit.
A dot '.', followed by at least one digit.
An integer can be split up into these components (in order):

(Optional) A sign character (either '+' or '-').
At least one digit.
For example, all the following are valid numbers: ["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"], while the following are not valid numbers: ["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"].

Given a string s, return true if s is a valid number.

 

Example 1:

Input: s = "0"
Output: true
Example 2:

Input: s = "e"
Output: false
Example 3:

Input: s = "."
Output: false
Example 4:

Input: s = ".1"
Output: true
 

Constraints:

1 <= s.length <= 20
s consists of only English letters (both uppercase and lowercase), digits (0-9), plus '+', minus '-', or dot '.'.
*/


class Solution {
public:
    bool isNumber(string s) {
        int state = 0;
		// (1) T0: Digit: 0-9
		// (2) T1: Sign: '+', '-'
		// (3) T2: 'e'
		// (4) T3: '.'
		// (5) T4: Blank
		// (6) T5: Others
        vector<vector<int> > transTable = {
        	// Q0: initial states; can accept digit (go to Q2), sign (go to Q1), 
        	// '.' (has not found any digit, so go to Q3), blank (stay at Q0), other input lead to rejection
            {2, 1, -1, 3, 0, -1}, 
            // Q1: find sign at the beginning; can accept digit (go to Q2), 
            // '.' (has not found any digit, so go to Q3), other input lead to rejection
            {2, -1, -1, 3, -1, -1},
            // Q2: find digit, but has not found '.'; can accept digit (stay at Q2), 
            // 'e' (go to Q5), '.' (now find digit, can go to Q4), blank (go to Q8), other input lead to rejection
            {2, -1, 5, 4, 8, -1},
            // Q3: find '.', but has not found any digit; 
            // can only accept digit (find digit, now can go to Q4), other input lead to rejection
            {4, -1, -1, -1, -1, -1},
            // Q4: find '.', and has already find some digits; 
            // can accept digit (stay at Q4), 'e' (go to Q5), blank (go to Q8), other input lead to rejection
            {4, -1, 5, -1, 8, -1},
            // Q5: find 'e'; can accept digit (digit before 'e' and after 'e' can lead to different states, so go to Q7), 
            // sign (sign before 'e' and after 'e' can lead to different states, so go to Q6), other input lead to rejection
            {7, 6, -1, -1, -1, -1},
            // Q6: find sign after e; can only accept digit (go to Q7), other input lead to rejection
            {7, -1, -1, -1, -1, -1},
            // Q7: find digit after e; can accept digit (stay at Q7), and blank (go to Q8)
            {7, -1, -1, -1, 8, -1}, 
            // Q8: find blank; can only accept blank (Q8), other input lead to rejection
            {-1, -1, -1, -1, 8, -1}
        };
        bitset<9> validStates("110010100"); 
        for(char c: s) {
            int type = inputType(c);
            state = transTable[state][type];
            if(state == -1) return false;
        }
        return validStates[state];
    }
    
private:
    int inputType(char c) { // use type ID as index to get next state in the transition table.
        if(isdigit(c)) return 0; // T0
        if(c == '+' || c == '-') return 1; // T1
        if(c == 'e' || c == 'E') return 2; // T2
        if(c == '.') return 3; // T3
        if(c == ' ') return 4; // T4
        else return 5; // T5
    }
};