## In-place modification of vector

```cpp
int dfs(vector<vector<int>>& matrix, int i, int j) {
  if (i < 0 || i > matrix.size() - 1 || j < 0 || j > matrix[0].size() - 1 || matrix[i][j] == -1) return INT_MAX;
  int d = matrix[i][j];
  // -1 : visited
  matrix[i][j] = -1;
  // logic goes here
  // e.g.
  d = min({
    d, 
    dfs(matrix, i + 1, j) + 1, 
    dfs(matrix, i - 1, j) + 1,
    dfs(matrix, i, j + 1) + 1, 
    dfs(matrix, i, j - 1) + 1}
  );
  // inplace update
  matrix[i][j] = d;
  return d;
}
```