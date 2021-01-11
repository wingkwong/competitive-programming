N, M = map(int, input().split())
INF = 10 ** 18
A = [INF] + list(map(int, input().split()))
G = [[0] for i in range(N + 1)]
for i in range(M):
    X, Y = map(int, input().split())
    G[Y].append(X)
dp = [INF for i in range(N + 1)]
ans = -INF
for i in range(1, N + 1):
    m = min(dp[j] for j in G[i])
    ans = max(ans, A[i] - m)
    dp[i] = min(m, A[i])
print(ans)
