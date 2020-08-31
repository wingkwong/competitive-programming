class Solution:
    def solve(self, s0, s1):
        s=s0.lower().split()
        t=s1.lower().split()
        return len(set(s)&set(t))