# [Minimum Absolute Difference in an Array](https://www.hackerrank.com/challenges/minimum-absolute-difference-in-an-array/problem)

![image](https://user-images.githubusercontent.com/35857179/79742990-5b369d80-8336-11ea-85ad-0a6c0dfa6c57.png)

Sample Input
```
3
3 -7 0
```

Sample Output
```
3
```

The first approach is to loop through the array between 0..n-1, 1..n-2, and 2..n-3, and so on. However, this approach is not ideal because we are finding all the differences. Instead, 
We can sort the array first because the values that are closest to one another produces the least difference such as (10,8) < (10,1). We can use C++ STL to solve this problem by calculating the difference between each adjacent element, and returning the minimum value of the array. 

## Reference:
- https://www.geeksforgeeks.org/std-adjacent_difference-in-cpp/