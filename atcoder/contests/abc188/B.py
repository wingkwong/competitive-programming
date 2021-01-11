n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
print('Yes' if sum(x * y for x, y in zip(a, b)) == 0 else 'No')