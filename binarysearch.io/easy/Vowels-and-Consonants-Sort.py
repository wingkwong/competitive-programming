class Solution:
    def solve(self, s):
        arr = sorted(s, key=lambda c: (c not in 'aeiou', c))
        return "".join(arr)