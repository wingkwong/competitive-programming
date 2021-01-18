from collections import Counter
 
N, K = map(int, input().split())
a = list(map(int, input().split()))
b = Counter(a)
i, ans, mi = 0, 0, K
while i in b:
    mi = min(b[i], mi)
    ans += mi
    i += 1
print(ans)