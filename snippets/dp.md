## Minimum (Maximum) Path to Reach a Target

```cpp
for (int i = 1; i <= target; ++i) {
  for (int j = 0; j < ways.size(); ++j) {
    if (ways[j] <= i) {
      dp[i] = min(dp[i], dp[i - ways[j]] + cost / path / sum);
    }
  }
}

return dp[target]
```

## Distinct Ways

```cpp
for (int i = 1; i <= target; ++i) {
  for (int j = 0; j < ways.size(); ++j) {
    if (ways[j] <= i) {
      dp[i] += dp[i - ways[j]];
    }
  }
}
 
return dp[target]
```

Merging Intervals

```cpp
for (int l = 1; l < n; l++) {
  for (int i = 0; i < n - l; i++) {
    int j = i + l;
    for (int k = i; k < j; k++) {
      dp[i][j] = max(dp[i][j], dp[i][k] + result[k] + dp[k + 1][j]);
    }
  }
}

return dp[0][n - 1]
```

## DP on string 

```cpp
// i - indexing string s1
// j - indexing string s2
for (int i = 1; i <= n; ++i) {
  for (int j = 1; j <= m; ++j) {
    if (s1[i - 1] == s2[j - 1]) {
      dp[i][j] = /*code*/;
    } else {
      dp[i][j] = /*code*/;
    }
  }
}
```

## Decision Making

```cpp
// i - indexing a set of values
// j - options to ignore j values
for (int i = 1; i < n; ++i) {
  for (int j = 1; j <= k; ++j) {
    dp[i][j] = max({dp[i][j], dp[i - 1][j] + arr[i], dp[i - 1][j - 1]});
    dp[i][j - 1] = max({dp[i][j - 1], dp[i - 1][j - 1] + arr[i], arr[i]});
  }
}
```
