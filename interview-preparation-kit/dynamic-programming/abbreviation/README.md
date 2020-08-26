# [Abbreviation](https://www.hackerrank.com/challenges/abbr/problem)

![image](https://user-images.githubusercontent.com/35857179/81190698-c1841700-8fea-11ea-928b-73a761594a48.png)

Sample Input
```
1
daBcd
ABC
```

Sample Output
```
YES
```

Using a simple DP approach can resolve this problem. Let's say we have ``dp[i,j]``, we set it to 1 if there is a way to transform the first ``i`` characters of ``A`` into the first ``j`` characters of ``B``. If it is not possible to do that, set it to 0. If ``dp[asz][bsz]`` is 1, return ``YES``, else return ``NO``. We just need to figure out which states can be achievable. 

```cpp
// AbCdE
// AFE
//     A F E
//   1 0 0 0 
// A 0 1 0 0 
// b 1 1 0 0 
// C 0 0 0 0 
// d 1 0 0 0 
// E 0 0 0 0
```