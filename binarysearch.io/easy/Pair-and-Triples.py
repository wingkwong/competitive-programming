class Solution:
    def solve(self, s):
        c = Counter(s)
        pair = 0
        for k, v in c.items():
            remainder = v % 3
            if remainder == 2:
                if pair:
                    return False
                pair = 1
            elif remainder == 1:
                return False
            # else triplets
        return pair == 1