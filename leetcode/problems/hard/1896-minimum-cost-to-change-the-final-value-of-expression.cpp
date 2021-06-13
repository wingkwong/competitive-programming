/*
Minimum Cost to Change the Final Value of Expression
https://leetcode.com/problems/minimum-cost-to-change-the-final-value-of-expression/

You are given a valid boolean expression as a string expression consisting of the characters '1','0','&' (bitwise AND operator),'|' (bitwise OR operator),'(', and ')'.

For example, "()1|1" and "(1)&()" are not valid while "1", "(((1))|(0))", and "1|(0&(1))" are valid expressions.
Return the minimum cost to change the final value of the expression.

For example, if expression = "1|1|(0&0)&1", its value is 1|1|(0&0)&1 = 1|1|0&1 = 1|0&1 = 1&1 = 1. We want to apply operations so that the new expression evaluates to 0.
The cost of changing the final value of an expression is the number of operations performed on the expression. The types of operations are described as follows:

Turn a '1' into a '0'.
Turn a '0' into a '1'.
Turn a '&' into a '|'.
Turn a '|' into a '&'.
Note: '&' does not take precedence over '|' in the order of calculation. Evaluate parentheses first, then in left-to-right order.

 

Example 1:

Input: expression = "1&(0|1)"
Output: 1
Explanation: We can turn "1&(0|1)" into "1&(0&1)" by changing the '|' to a '&' using 1 operation.
The new expression evaluates to 0. 
Example 2:

Input: expression = "(0&0)&(0&0&0)"
Output: 3
Explanation: We can turn "(0&0)&(0&0&0)" into "(0|1)|(0&0&0)" using 3 operations.
The new expression evaluates to 1.
Example 3:

Input: expression = "(0|(1|0&1))"
Output: 1
Explanation: We can turn "(0|(1|0&1))" into "(0|(0|0&1))" using 1 operation.
The new expression evaluates to 0.
 

Constraints:

1 <= expression.length <= 105
expression only contains '1','0','&','|','(', and ')'
All parentheses are properly matched.
There will be no empty parentheses (i.e: "()" is not a substring of expression).
*/

class Solution {
public:
    array<char, 2> eval(vector<array<char, 2>> &exp, int i) {
        if (i == 0) return exp[0];
        auto left = eval(exp, i - 2), right = exp[i];
        int v1 = left[0] - '0', v2 = right[0] - '0', cost = 1; 
        if (exp[i - 1][0] == '|') {
            if (v1 == v2) cost = min(left[1], right[1]) + (v1 == 1);
            return { v1 | v2 ? '1' : '0', (char)cost};
        }
        if (v1 == v2) cost = min(left[1], right[1]) + (v1 == 0);
        return { v1 & v2 ? '1' : '0', (char)cost};
    }
    int minOperationsToFlip(string expression) {
        vector<vector<array<char, 2>>> st(1);
        for (auto ch : expression) {
            if (ch == '(') st.push_back(vector<array<char, 2>>());
            else if (ch == ')') {
                auto val = eval(st.back(), st.back().size() - 1);
                st.pop_back();
                st.back().push_back(val);
            }
            else st.back().push_back({ch, 1});
        }
        return eval(st.back(), st.back().size() - 1)[1];
    }
};