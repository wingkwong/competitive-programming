# [Taum and B'day](https://www.hackerrank.com/challenges/taum-and-bday/problem)

![image](https://user-images.githubusercontent.com/35857179/80217132-be476d80-8671-11ea-86df-5977fbad7fe0.png)

Sample Input
```
5
10 10
1 1 1
5 9
2 3 4
3 6
9 1 1
7 7
4 2 1
3 3
1 9 2
```

Sample Output
```
20
37
12
35
12
```

We need to find out that if it is worth to convert one color gift to the other color based on the cost ``z``. Basically we only do that when ``wc+z`` is less than ``bc`` for black gifts 

```cpp
b*min(bc,wc+z)
```

or when ``bc+z`` is less than ``wc`` for white gifts. 
```cpp
w*min(wc,bc+z))
```

so the answer is their sum.
```cpp
b*min(bc,wc+z) + w*min(wc,bc+z)
```