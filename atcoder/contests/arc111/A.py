n, m = map(int, input().split())
print(pow(10, n, m * m) // m % m)