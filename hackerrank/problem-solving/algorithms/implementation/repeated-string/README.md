# [Repeated String](https://www.hackerrank.com/challenges/repeated-string/problem)

![image](https://user-images.githubusercontent.com/35857179/79974372-d2516a80-84cb-11ea-8ebc-c15b8f55a321.png)

Sample Input
```
aba
10
```

Sample Output
```
7
```

Explanation
The first n=10 letters of the infinite string are abaabaabaa. Because there are 7 a's, we print 7 on a new line.

If ``s`` only contains letter a, we can directly print ``n``. 
```cpp
if(s.size()==1 && s=="a") cout << n;
```

otherwise, we calculate the number of a in a given string.
```cpp
c=count(s.begin(),s.end(),'a')
```

We then calculate how manys times ``s`` needs to repeat without exceeding ``n``.
```cpp
r=n/s.size()
```

Take the sample input as an example, there are 2 a's and ``n`` is 10. It will repeat three times leaving a single ``a`` at the end. 

```
abaabaaba a
```

We also need to take care of the last part. To find out how many a's there, we can use ``n%s.size()``. In this case, it is 1. Hence, we can calculate the number of a from ``s.begin()`` to ``s.begin()+n%s.size()``.
```cpp
count(s.begin(),s.begin()+(n%s.size()),'a')
```