# [Left Rotation](https://www.hackerrank.com/challenges/ctci-array-left-rotation/problem)

![image](https://user-images.githubusercontent.com/35857179/80590396-608a9b00-8a4e-11ea-89c4-e1e83a334535.png)

Sample Input
```
5 4
1 2 3 4 5
```

Sample Output
```
5 1 2 3 4
```

We can traverse the input and find the corresponding value by the following formula
```
(i+d)%n
```

where ``i`` is the current index, ``d`` is the number of left rotations and ``n`` is the size of the input.

```
ans[0] = a[4] = 5
ans[1] = a[0] = 1
ans[2] = a[1] = 2 
ans[3] = a[2] = 3
ans[4] = a[3] = 4
```