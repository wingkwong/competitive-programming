# [Diagonal Difference](https://www.hackerrank.com/challenges/diagonal-difference/problem)

Given a square matrix of size N×N, calculate the absolute difference between the sums of its diagonals. containing N space-separated integers describing the columns. Print the absolute difference between the two sums of the matrix's diagonals as a single integer.

Sample Input 
```
3
11 2 4
4 5 6
10 8 -12
```

Sample Output
```
15
```

The primary diagonal is
```
11
   5
     -12
```

If we find out [x][y] of each value of the diagonal, we got
```
        [x][y]
11  :   [0][0]
5   :   [1][1]
-12 :   [2][2]
```

Hence, we can sum up the value like this

```cpp
d1 += arr[i][i];
```
Sum across the primary diagonal: 11 + 5 - 12 = 4

The secondary diagonal is
```
     4
   5
10
```
If we find out [x][y] of each value of the diagonal, we got
```
     [x][y]
4  : [0][2]
5  : [1][1]
10 : [2][0]
```

``x`` increases by 1 while ``y`` decreases by 1. ``i`` starts from 0. Hence, we got [n-i-1] for ``x`` and [i] for ``y``.
```cpp
d2 += arr[n-i-1][i];
```

Sum across the secondary diagonal: 4 + 5 + 10 = 19

Difference: |4 - 19| = 15

Call ``abs`` to return the absolute value of parameter ``d1-d2``
```
abs(d1 - d2);
```