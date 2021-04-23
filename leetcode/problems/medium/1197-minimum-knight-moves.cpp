/*
Minimum Knight Moves
https://leetcode.com/problems/minimum-knight-moves/

In an infinite chess board with coordinates from -infinity to +infinity, you have a knight at square [0, 0].

A knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal direction, then one square in an orthogonal direction.



Return the minimum number of steps needed to move the knight to the square [x, y].  It is guaranteed the answer exists.

 

Example 1:

Input: x = 2, y = 1
Output: 1
Explanation: [0, 0] → [2, 1]
Example 2:

Input: x = 5, y = 5
Output: 4
Explanation: [0, 0] → [2, 1] → [4, 2] → [3, 4] → [5, 5]
 

Constraints:

|x| + |y| <= 300

*/

class Solution {
public:
    int dp[305][305] = {0};
    
    int go(int x, int y) {
        x = abs(x), y = abs(y);
        if(x > y) swap(x, y);
        if(dp[x][y] != 0) return dp[x][y];
        return dp[x][y] = 1 + min(go(x - 2, y - 1), go(x - 1, y - 2));
    }
    
    int minKnightMoves(int x, int y) {
        dp[0][0] = 0, dp[0][1] = 3;
        dp[0][2] = 2, dp[1][1] = 2;
        dp[1][2] = 1, dp[2][2] = 4;
        x = abs(x), y = abs(y);
        if(x > y) swap(x, y);
        if(x <= 2 && y <= 2) return dp[x][y];
        return go(x, y);
    }
};