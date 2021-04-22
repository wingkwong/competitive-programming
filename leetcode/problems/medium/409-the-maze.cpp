/*
The Maze
https://leetcode.com/problems/the-maze/

There is a ball in a maze with empty spaces (represented as 0) and walls (represented as 1). The ball can go through the empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

Given the m x n maze, the ball's start position and the destination, where start = [startrow, startcol] and destination = [destinationrow, destinationcol], return true if the ball can stop at the destination, otherwise return false.

You may assume that the borders of the maze are all walls (see examples).

 

Example 1:


Input: maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [4,4]
Output: true
Explanation: One possible way is : left -> down -> left -> down -> right -> down -> right.
Example 2:


Input: maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [3,2]
Output: false
Explanation: There is no way for the ball to stop at the destination. Notice that you can pass through the destination but you cannot stop there.
Example 3:

Input: maze = [[0,0,0,0,0],[1,1,0,0,1],[0,0,0,0,0],[0,1,0,0,1],[0,1,0,0,0]], start = [4,3], destination = [0,1]
Output: false
 

Constraints:

m == maze.length
n == maze[i].length
1 <= m, n <= 100
maze[i][j] is 0 or 1.
start.length == 2
destination.length == 2
0 <= startrow, destinationrow <= m
0 <= startcol, destinationcol <= n
Both the ball and the destination exist in an empty space, and they will not be in the same position initially.
The maze contains at least 2 empty spaces.

*/

class Solution {
public:
    bool dfs(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination, vector<vector<int>>& vis) {
        if(vis[start[0]][start[1]]) return false;
        if(start[0] == destination[0] && start[1] == destination[1]) return true;
        vis[start[0]][start[1]] = 1;
        int u = start[0] - 1;
        int d = start[0] + 1;
        int l = start[1] - 1;
        int r = start[1] + 1;
        vector<int> new_start;
        // up
        while(u >= 0 && maze[u][start[1]] == 0) u--;
        new_start = {u + 1, start[1]};
        if(dfs(maze, new_start, destination, vis)) return true;
        // down
        while(d < maze.size() && maze[d][start[1]] == 0) d++;
        new_start = {d - 1, start[1]};
        if(dfs(maze, new_start, destination, vis)) return true;
        // left
        while(l >= 0 && maze[start[0]][l] == 0) l--;
        new_start = {start[0], l + 1};
        if(dfs(maze, new_start, destination, vis)) return true;
        // right
        while(r < maze[0].size() && maze[start[0]][r] == 0) r++;
        new_start = {start[0], r - 1};
        if(dfs(maze, new_start, destination, vis)) return true;
        return false;
    }
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        return dfs(maze, start, destination, vis);
    }
};