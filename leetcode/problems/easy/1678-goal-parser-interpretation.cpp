/*
Goal Parser Interpretation
https://leetcode.com/problems/goal-parser-interpretation/

You own a Goal Parser that can interpret a string command. The command consists of an alphabet of "G", "()" and/or "(al)" in some order. The Goal Parser will interpret "G" as the string "G", "()" as the string "o", and "(al)" as the string "al". The interpreted strings are then concatenated in the original order.

Given the string command, return the Goal Parser's interpretation of command.

 

Example 1:

Input: command = "G()(al)"
Output: "Goal"
Explanation: The Goal Parser interprets the command as follows:
G -> G
() -> o
(al) -> al
The final concatenated result is "Goal".
Example 2:

Input: command = "G()()()()(al)"
Output: "Gooooal"
Example 3:

Input: command = "(al)G(al)()()G"
Output: "alGalooG"
 

Constraints:

1 <= command.length <= 100
command consists of "G", "()", and/or "(al)" in some order.
*/

class Solution {
public:
    string interpret(string command) {
        int n = (int) command.size();
        string s;
        for(int i = 0; i < n;) {
            if(command[i] == 'G') s += "G", i++;
            else if(command[i] == '(') {
                if(i + 1 < n && command[i + 1] == ')') s += "o", i += 2;
                if(i + 3 < n && command[i + 1] == 'a' && command[i + 2] == 'l' && command[i + 3] == ')') s += "al", i += 3;
            } else i++;
        }
        return s;
    }
};