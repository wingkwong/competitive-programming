# [The Longest Increasing Subsequence](https://www.hackerrank.com/challenges/longest-increasing-subsequent/problem)

The task is to find the length of the longest subsequence in a given array of integers such that all elements of the subsequence are sorted in strictly ascending order. This is called the Longest Increasing Subsequence (LIS) problem.

For example, the length of the LIS for [15,27,14,38,26,55,46,65,85] is 6 since the longest increasing subsequence is [15,27,38,55,65,85]

Sample Input 
```
5
2
7
4
3
8
```

Sample Output 
```
3
```

Explanation 

In the array [2,7,4,3,8], the longest increasing subsequence is [2,7,8]. It has a length of 3.

Given that an array with a length of `n`, we can create two vectors with the same size - one called ``l`` for holding the length, another one ``s`` for holding the sub-sequence index. 

```
arr [2,7,4,3,8]
n   [1,1,1,1,1]
s   [0,0,0,0,0]
```

If we list out the index, we should see
```
idx  0,1,2,3,4
arr [2,7,4,3,8]
```

let's say we have ``i`` and ``j`` where ``i`` starts from ``1..n-1`` and j starts from ``0..i``.
```
     j,i
idx  0,1,2,3,4
arr [2,7,4,3,8]
```

we check if ``arr[j]`` is lesser than ``arr[i]``. If so, check if ``l[j]+1`` is greater than ``l[i]``

In this case, ``arr[j]`` is 2 which is lesser than ``arr[i]`` which is 7. So we add ``l[j]`` by 1 to see if it is greater than ``l[i]``. 

It is. So we set ``l[j]+1`` to ``l[i]`` and set the index ``j`` to ``s[i]``.

Repeat the above steps till ``i`` reaches ``n-1``. 

Find out the maximum value of ``l``. That is the length of the LIS. 


```cpp
int lis(vi a, int n){
    vi l(n);
    vi s(n); 
    int max=0;

    l[0]=1;
    FOR(i, 1, n){
        l[i] = 1;
        REP(j,i){
            if(a[j] < a[i]){
                if(l[j]+1>l[i]){
                    l[i]=l[j]+1;
                    s[i]=j;
                    if(l[i]>max) max=l[i];
                }
            }
        }
    }
    return max;
}

int main()
{
    // SKIPPED
}
```

However, this approach is ``O(N^2)`` which gives you Terminated due to timeout (TLE) Error. We need a faster approach to resolve this problem. 

Supposing there is a vector called ``vi``. The strategy is 

- If ``vi`` is empty, set the input ``a`` to ``vi[0]``.
- If ``vi`` is not empty and the input ``a`` is the largest value of ``vi``, append ``a`` at the end
- If ``vi`` is not empty and the input ``a`` is in between, find the correct index and replace the existing value. 

We can implement a binary search function to look for the correct index or we can just use STL. The answer is the size of ``vi``.

Final Solution
```cpp

int main()  
{ 
    FAST_INP;
    int n,a;

    cin >> n;
    vi v;

    REP(i,n){
        vi::iterator it;

        cin >> a;
        if(i==0) v.push_back(a);
        else {
            it=lower_bound(v.begin(),v.end(),a);
            int k=it-v.begin();
            if(k==v.size()) v.push_back(a);
            else v[k]=a;
        }
    }
    cout << v.size();
    return 0; 
} 
```

## References:
- [Longest Increasing Subsequence (Dynamic Programming)](https://www.youtube.com/watch?v=E6us4nmXTHs&feature=emb_rel_end)
- [Longest Increasing Subsequence Size (N log N)](https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/)
