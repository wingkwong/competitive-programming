N, C = map(int, input().split())
l = [tuple(map(int, input().split())) for i in range(N)]
s = set()
for a, b, c in l:
    s.add(a)
    s.add(b + 1)
d = {}
s = sorted(list(s))
for i, j in enumerate(s):
    d[j] = i
m = [0] * (len(s) + 1)
for a, b, c in l:
    m[d[a]] += c
    m[d[b + 1]] -= c
ans = 0
for i in range(len(s) - 1):
    c = m[i] if m[i] < C else C
    ans += (s[i + 1] - s[i]) * c
    m[i + 1] += m[i]
print(ans) 