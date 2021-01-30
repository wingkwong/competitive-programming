#!/bin/python3

import os
import sys

#
# Complete the handshake function below.
#
def handshake(n):
    # p1 p2 p3 (n = 3)
    # p1 ----- (2)
    #    p2 -- (1)
    #          (0)
    ans = 0 
    for i in range(1, n + 1):
        if i > 0:
            ans += n - i 
    return ans

def handshake_solution2(n):
    # (n - 1) + (n - 1 - 1) + (n - 1 - 1 - 1) + ... + 3 + 2 + 1
    # = (n - 1) + (n - 2) + (n - 3) + ... + 3 + 2 + 1
    # = (n - 1) * n / 2
    return (n - 1) * n // 2

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        n = int(input())

        result = handshake(n)

        fptr.write(str(result) + '\n')

    fptr.close()
