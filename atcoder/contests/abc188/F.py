x, y = map(int,input().split())
dp = {}

def dfs(n):
    if n == x:
        return 0
    if abs(n - x) == 1:
        return 1
    if n <= x:
        return x - n
    if n in dp:
        return dp[n]
    l = n // 2
    r = (n + 1) // 2
    res = n - x
    res = min(res, abs(l * 2 - n) + 1 + dfs(l))
    res = min(res, abs(r * 2 - n) + 1 + dfs(r))
    dp[n] = res
    return res

print(dfs(y))