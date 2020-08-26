# [2D Array - DS](https://www.hackerrank.com/challenges/2d-array/problem)

Given a 6x6 2D Array, arr:
```
1 1 1 0 0 0
0 1 0 0 0 0
1 1 1 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
```

We define an hourglass in A to be a subset of values with indices falling in this pattern in arr's graphical representation:
```
a b c
  d
e f g
```

There are 16 hourglasses in arr, and an hourglass sum is the sum of an hourglass' values. Calculate the hourglass sum for every hourglass in arr, then print the maximum hourglass sum.

For example, given the 2D array:
```
-9 -9 -9  1 1 1 
 0 -9  0  4 3 2
-9 -9 -9  1 2 3
 0  0  8  6 6 0
 0  0  0 -2 0 0
 0  0  1  2 4 0
 ```

We calculate the following  hourglass values:
```
-63, -34, -9, 12, 
-10, 0, 28, 23, 
-27, -11, -2, 10, 
9, 17, 25, 18
```

Our highest hourglass value is  from the hourglass:
```
0 4 3
  1
8 6 6
```

Each value has its ``i`` and ``j`` values. For example, we can convert
```
1 1 1 0 0 0
0 1 0 0 0 0
1 1 1 0 0 0
0 0 2 4 4 0
0 0 0 2 0 0
0 0 1 2 4 0
```

to 
```
[0][0] [0][1] [0][2] [0][3] [0][4] [0][5]
[1][0] [1][1] [1][2] [1][3] [1][4] [1][5]
[2][0] [2][1] [2][2] [2][3] [2][4] [2][5]
[3][0] [3][1] [3][2] [3][3] [3][4] [3][5]
[4][0] [4][1] [4][2] [4][3] [4][4] [4][5]
[5][0] [5][1] [5][2] [5][3] [5][4] [5][5] 
```

We can break each hourglass into 3 rows and directly select the values we want. 

For example,
```
1 1 1 
  1 
1 1 1 
```

We can convert it to this format
```
[0][0] [0][1] [0][2]
       [1][1]
[2][0] [2][1] [2][2]
```

The sum of the top row is 
```cpp
a[i][j]+a[i][j+1]+a[i][j+2]
```

The sum of the middle row is 
```cpp
a[i+1][j+1]
```

The sum of the last row is 
```cpp
a[i+2][j]+a[i+2][j+1]+a[i+2][j+2]
```

For 6 space-separated integers arr, it only moves 4 times to reach the end.  So we need to createa two for loops - ``i..4`` and ``j..4`` where ``i`` and ``j`` both start from ``0``. 

Calculate each sum and check if it is greater than max, print the max at the end.