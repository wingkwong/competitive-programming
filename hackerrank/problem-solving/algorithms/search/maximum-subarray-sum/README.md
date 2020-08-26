# [Maximum Subarray Sum](https://www.hackerrank.com/challenges/maximum-subarray-sum/problem)

![image](https://user-images.githubusercontent.com/35857179/80171763-cbd30800-861d-11ea-9a0f-4721e42e3e40.png)

The first approach is to use brute force to find out all the possibilties.

```
Input : arr[] = { 3, 3, 9, 9, 5 }

{ 9 } => 9%7 = 2
{ 3 } => 3%7 = 3
{ 5 } => 5%7 = 5
{ 9, 5 } => 14%7 = 2
{ 9, 9 } => 18%7 = 4
{ 3, 9 } => 12%7 = 5
{ 3, 3 } => 6%7 = 6
{ 3, 9, 9 } => 21%7 = 0
{ 3, 3, 9 } => 15%7 = 1
{ 9, 9, 5 } => 23%7 = 2
{ 3, 3, 9, 9 } => 24%7 = 3
{ 3, 9, 9, 5 } => 26%7 = 5
{ 3, 3, 9, 9, 5 } => 29%7 = 1
```

An efficient way is to compute prefix sum of array, i.e. ``prefixi = (arr[0] + arr[1] + .... arr[i] ) % m``. Find the maximum sun ending with every index (``maxSumi = (prefixi - prefixj + m) % m``) and finally return overall maximum. In order to find maximum sum ending at index at index, we need to find the starting point of maximum sum ending with ``i``, i.e. `` subarray(start+1,i)``. 

Since ``prefixi - prefixj`` can be negative so we need to add ``m`` to it. In modular arithmetic, adding ``m`` does not make a different. If you miss it, you will fail the following test case. 

```
1
3 5
1 5 9
```

For example, if ``i`` is 4, we have 
```
{ 3, 3, 9, 9, 5 } => 29%7 = 1
```

If start is ``0``, the subarray is (start+1,i) -> (0+1,4) -> (1,4), which is ``{ 3, 9, 9, 5 }``. The mod sum of this sub array is 
```
prefixi: { 3 } => 3%7 = 3
prefixj: { 3, 3, 9, 9, 5 } => 29%7 = 1
maxSumi = (prefixi - prefixj + m) % m
maxSumi = (1 - 3 + 7) % 7
maxSumi= 5
```

We can verify it manually
```
{ 3, 9, 9, 5 } => 26%7 = 5
```

To do so, we can insert mod sum of each index to Set and find the first element that is not less than the value ``prefix+1`` and check if ``maxSumi`` is greater than the current max or not. If so, we take the largest value as max.

## Reference:
- https://www.geeksforgeeks.org/maximum-subarray-sum-modulo-m/

