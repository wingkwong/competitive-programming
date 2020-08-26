# [Minimum Swaps 2](https://www.hackerrank.com/challenges/minimum-swaps-2/problem)

![image](https://user-images.githubusercontent.com/35857179/80280087-5b6ada80-8734-11ea-9548-69f9162551e8.png)

We can keep swapping the same index until the value matches the current index ``i``. 

```cpp
swap(arr[i], arr[arr[i]-1]);
```

```
i   arr                        ans
0   [7, 1, 3, 2, 4, 5, 6]      0
0   [6, 1, 3, 2, 4, 5, 7]      1
0   [5, 1, 3, 2, 4, 6, 7]      2
0   [4, 1, 3, 2, 5, 6, 7]      3
0   [2, 1, 3, 4, 5, 6, 7]      4
0   [1, 2, 3, 4, 5, 6, 7]      5
```

If it matches, check for the next index. 

```cpp
if(arr[i]==i+1) continue;
```