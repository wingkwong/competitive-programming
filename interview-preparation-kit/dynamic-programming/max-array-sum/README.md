# [Max Array Sum](https://www.hackerrank.com/challenges/max-array-sum/problem)

![image](https://user-images.githubusercontent.com/35857179/81059514-1d737080-8f03-11ea-921d-2c203377a46f.png)

Sample Input
```
5
3 7 4 6 5
```

Sample Output 0
```
13
```

First we should think about the base cases. Given that the minimum value is 1, we can return the first element if n is 1. If n is 2, we pick the maximum sum from ``arr[0]`` and ``arr[1]``. To do so, we create an array ``dp`` with the size same as ``arr`` to store the maximum sum at index ``i``. 

```cpp
dp[0]=arr[0];
dp[1]=max(arr[0],arr[1]);
```

Starting from the third element, we either pick 

- the current value only (which is greater than the previous accumlated sum)
- the previous value only (which is greater than the current value and its previous value)
- the second previous value plus the current value (because we cannot sum adjacent elements)

```cpp
dp[i] = max({dp[i-1], arr[i],dp[i-2]+arr[i]});
```

At the end, return ``dp[sz-1]`` which is our maximum sum.