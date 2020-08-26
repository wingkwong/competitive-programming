# [Ice Cream Parlor](https://www.hackerrank.com/challenges/icecream-parlor/problem)

![image](https://user-images.githubusercontent.com/35857179/79975973-720ff800-84ce-11ea-8080-cf8b5c463fc1.png)

Sample Input
```
2
4
5
1 4 5 3 2
4
4
2 2 4 3
```

Sample Output
```
1 4
1 2
```

It's like Two Sum question. We insert ``v`` to a map if ``m-v`` is not found or print the result if it is found.

Take the first case in the sample input as an example, we are looking for those two numbers which add each other equal to 4. 

```
k id
----
1 0 
4 1 
5 2
```

By the time we check 3, we found that ``m-v`` (4-3) which exists in the map. Hence, ``mp[m-v]`` and the current value ``v`` are the answer.