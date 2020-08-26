# [Count Triplets](https://www.hackerrank.com/challenges/count-triplets-1/problem)

![image](https://user-images.githubusercontent.com/35857179/81278735-a8ca3e80-9088-11ea-95aa-e81ce7a5af14.png)


Sample Input 0
```
4 2
1 2 2 4
```

Sample Output 0
```
2
```

Create two maps to hold the values for building 2/3 triplets and 3/3 triplets. No division is necessary in this case. Take the sample input 0 as an exampe, for the first value, ``ans`` and ``m3[v*r]`` is 0 as ``m3`` and ``m2`` are still empty. For the first iternation, it only set ``m2[1*2]`` to 1.

For the second iteration, the value is 2 and ``m3[2]`` is still empty. However ``m2[2]`` is 1 as it is updated in previous iteration so that ``m3[4]`` is now 1.

For the third iteration, the value is 2 again and ``m3[2]`` is still empty. ``m3[4]`` is updated again, which is 2. 

For the last iternation, ``m3[4]`` is 2 and ``ans`` becomes 2. At the end, it returns 2. 


```
i=0 - value=1
m2[2]=1

i=1 - value=2
m3[4]=1
m2[4]=1

i=2 - value=2
m3[4]=2
m2[4]=2

i=3 - value=4
ans=m3[4]
ans=2
```