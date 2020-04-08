# [Staircase](https://www.hackerrank.com/challenges/staircase/problem)

Consider a staircase of size n=4 :
```
   #
  ##
 ###
####
```

Observe that its base and height are both equal to ``n``, and the image is drawn using ``n`` symbols and spaces. The last line is not preceded by any spaces.

Write a program that prints a staircase of size .

Sample Input
```
6 
```
Sample Output
```

     #
    ##
   ###
  ####
 #####
######
```

Given that ``n=4``, we can list out how many spaces ``s`` and hash symbols ``h`` are required.
```
   #  s: 3 - h:1 
  ##  s: 2 - h:2
 ###  s: 1 - h:3
####  s: 0 - h:4
```

The pattern can be easily observed. As ``n`` increases, ``s`` decreases while ``h`` increases. And we can notice that ``n-i-1`` spaces and ``i+1`` hash symbols for row ``i`` starting from 0 are needed. We can utilise string initialisation to resolve this question and concatenate the spaces and hash symbols.  