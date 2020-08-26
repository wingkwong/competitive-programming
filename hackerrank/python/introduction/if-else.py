#!/bin/python

import math
import os
import random
import re
import sys


# Approach 1
if __name__ == '__main__':
    n = int(raw_input().strip())
    # If n is odd, print Weird
    if n%2:
        print "Weird"
    else:
    # If n is even and in the inclusive range of 2 to 5, print Not Weird
        if(n>=2 and n<=5):
            print "Not Weird"
    # If n is even and in the inclusive range of 6 to 20, print Weird
        if(n>=6 and n<=20):
            print "Weird"
    # If n is even and greater than 20, print Not Weird
        if(n>20):
            print "Not Weird"


# Approach 2 
if __name__ == '__main__':
    n = int(raw_input().strip())
    opt = {
        True: "Not Weird",
        False: "Weird"
    }
    print(
        opt[
            n%2==0 and (n in range(2,6) or n>20)
        ]
    )