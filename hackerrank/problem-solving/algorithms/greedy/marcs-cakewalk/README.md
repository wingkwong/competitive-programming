# [Marc's Cakewalk](https://www.hackerrank.com/challenges/marcs-cakewalk/problem)

![image](https://user-images.githubusercontent.com/35857179/79744179-815d3d00-8338-11ea-8d84-3c62c1ecf444.png)

Sample Input
```
3
1 3 2
```

Sample Output
```
11
```

Since we need the minimum value, so we can sort the array in a descending order and apply the formula ``sum = sum + 2^i*v[i]`` to find out the final sum value.

```cpp
sort(v.rbegin(),v.rend());
REP(i,n) sum+=pow(2,i)*v[i];
cout<<sum;
```