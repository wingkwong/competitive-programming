n = int(input())
a = list(map(int,input().split()))
left = a[:1 << (n - 1)]
right = a[1 << (n - 1):]
print(a.index(min(max(left), max(right))) + 1)