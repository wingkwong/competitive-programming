# [Knapsack](https://www.hackerrank.com/challenges/unbounded-knapsack/problem)

Given an array of integers and a target sum, determine the sum nearest to but not exceeding the target that can be created. To create the sum, use any element of your array zero or more times.

For example, if arr=[2,3,4] and your target sum is 10, you might select [2,2,2,2,2], [2,2,2,3] or [3,3,3,1] . In this case, you can arrive at exactly the target.

Sample Input
```
2
3 12
1 6 9
5 9
3 4 4 4 8
```

Sample Output
```
12
9
```

Explanation

In the first test case, one can pick {6, 6}. In the second, we can pick {3,3,3}.


This is a unbounded knapsack so we cannot use the classic way to solve this problem. To solve it, we can break the problem into smaller problems first.

If we put the first item into the knapsack, then the remaining capacity would be ``W-w1``. So we can break it down to find out the maximum value ``max1`` if we pack the same item ``N`` times in a knapsack of capacity ``W-w1``. For the second item, we do the same thing to get ``max2`` so that it has a remaining capacity of ``W-w2``, and so on. 

Each item has a own value now but we have to add the original value to it. 

```
itemMax1 = max1 + v1
```

The maximum value is 

```
W = max(itemMax1,itemMax2,...,itemMaxN)
```

where ``W`` is the maximum value packed in the knapsack of capacity.

Psuedo code
```cpp
f(v[], w[], c) {
    // v: array of values
    // w: array of weights
    // c: capacity
    // n: length of the array

    // base case
    // if it is full, the total value of a 0 capacity knapsack is 0
    if(c==0) return 0;

    int[] m;

    // break it down to smaller problem
    // ----------------------------------------
    for(int i=0;i<n;i++){
        // if we can put item 1
        if(w[i]<c) m[i]=f(v,w,c-w[i]);
        // not enough space
        else m[i]=0; 
    }

    // add back the original value
    // ----------------------------------------
    for(int i=0;i<n;i++){
        // if we can put item 1
        if(w[i]<c) mm[i]=m[i] + v[i];
        // not enough space
        else mm[i]=0; 
    }

    // find the maximum value
    // ----------------------------------------
    int ans=mm[0];
    for(int i=1;i<n;i++){
        if(mm[i]>ans) ans=mm[i];
    }

    return ans;
}
```

However, we can use bottom-up dynamic programming solution for this problem to improve the above solution. 

As we may see that we only have one parameter ``c`` for the recursive method where ``c`` ranges from ``W`` to ``0`` and ``v[]`` and ``w[]`` remain unchanged. Therefore, we can store the results computed by the recursive function in a 1d array. 

```cpp
int dp[W+1];
```

We can set our base case to 0.

```cpp
dp[0] = 0;
```

We can turn 

```cpp
f(v,w,c-w[i]);
```

to 

```cpp
dp[c-w[i]]
```

and also from
```cpp
int ans=mm[0];
for(int i=1;i<n;i++){
    if(mm[i]>ans) ans=mm[i];
}

return ans;
```

to 

```cpp
dp[c]=mm[0];
for(int i=1;i<n;i++){
    if(mm[i]>dp[c]) dp[c]=mm[i];
}
```

and the result would be 

```cpp
return dp[c];
```

So we have the following structure
```cpp
dp[0] = 0

for C=0 ... W:
    for i=0 .. N:
        if w[i]<=C: 
            dp[i] = max ( dp[i], ( dp[C-w[i]] + v[i] ) )
        else 
            dp[i] = 0
```

In this question, there is no weight so we can consider weight is same as value. 

## References: 
- [Unbounded Knapsack (Repetition of items allowed)](https://www.geeksforgeeks.org/unbounded-knapsack-repetition-items-allowed/)
- [Lecture 13: The Knapsack Problem](http://www.es.ele.tue.nl/education/5MC10/Solutions/knapsack.pdf)