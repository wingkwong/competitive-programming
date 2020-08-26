/*
Path Crossing

Given a string path, where path[i] = 'N', 'S', 'E' or 'W', each representing moving one unit north, south, east, or west, respectively. You start at the origin (0, 0) on a 2D plane and walk on the path specified by path.

Return True if the path crosses itself at any point, that is, if at any time you are on a location you've previously visited. Return False otherwise.


Example 1:

Input: path = "NES"
Output: false 
Explanation: Notice that the path doesn't cross any point more than once.

Example 2:

Input: path = "NESWW"
Output: true
Explanation: Notice that the path visits the origin twice.
 

Constraints:

1 <= path.length <= 10^4
path will only consist of characters in {'N', 'S', 'E', 'W}
*/

class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_map<int,unordered_map<int, int>> m;
        int x=0,y=0;
        // origin point
        m[x][y]=1;
        for(char c:path){
            if(c=='N') y+=1;
            else if(c=='E') x+=1;
            else if(c=='S') y-=1;
            else if(c=='W') x-=1;
            // check if it s visited
            if(m[x][y]) return true;
            // if not, set it visited
            m[x][y]=1;
        }
        return false;
    }
};