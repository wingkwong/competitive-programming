/*
Latin Square

Given an N by N matrix of letters matrix, return whether there are exactly N different letters that appear in the matrix and each letter appears exactly once in each row and exactly once in each column.

Example 1
Input

matrix = [
    ["a", "b", "c"],
    ["c", "a", "b"],
    ["b", "c", "a"]
]
Output

true
Explanation

There are 3 different letters and each letter appears exactly once in each row and column.

Example 2
Input

matrix = [
    ["a", "b", "c"],
    ["d", "a", "a"],
    ["b", "b", "a"]
]
Output

false
Explanation

There are 4 different letters, and also "a" and "b" appear twice in the same row.
*/

#include "solution.hpp"
using namespace std;


class Solution {
    public:
    bool solve(vector<vector<string>>& matrix) {
        int n = matrix.size();
        vector<set<string>> row(n), col(n);
        set<string> s;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                row[i].insert(matrix[i][j]);
                col[j].insert(matrix[i][j]);
                s.insert(matrix[i][j]);
            }
        }
        if(s.size()!=n) return false;
        for(int i=0;i<n;i++){
            if(row[i].size()!=n||col[i].size()!=n) {
                return false;
            }
        }
        return true;
    }
};
