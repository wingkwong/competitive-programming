N = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
# c[i] = max(c[i - 1], max(a[0], a[1], ..., a[n - 1]) * b[i])
c = []
a_mx, b_mx, c_mx = 0, 0, 0
for i in range(N):
    a_mx = max(a_mx, a[i])
    c_mx = max(c_mx, a_mx * b[i])
    print(c_mx)