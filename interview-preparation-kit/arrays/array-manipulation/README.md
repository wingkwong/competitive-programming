# [Array Manipulation](https://www.hackerrank.com/challenges/crush/problem)

![image](https://user-images.githubusercontent.com/35857179/81464693-7b030800-91f6-11ea-8942-84064bbb5168.png)


Sample Input
```
5 3
1 2 100
2 5 100
3 4 100
```

Sample Output
```
200
```

Efficient approach using Prefix Sum Array :

1 : Run a loop for 'm' times, inputting 'a' and 'b'.
2 : Add k at index 'a' and subtract k from index 'b+1'.
3 : After completion of 'm' operations, compute the prefix sum array.
4 : Scan the largest element and we're done.

```
1    2    3    4   5 
100  0   -100  0   0
0    100   0   0   0      
0    0    100  0 -100
--------------------------
100 100  0    0  -100

ans=max=100+100=200
```

Final Solution
```cpp
int main()  
{ 
    FAST_INP;
    ll n,m,a,b,k,ans=0,t=0;
    cin >> n >> m;
    vector<ll> arr(n+1,0);
    TC(m){
        cin >> a >> b >> k;
        arr[a]+=k;
        if(b+1<=n) arr[b+1]-=k;
    }
    for(int i=1;i<=n;i++){
        t+=arr[i];
        ans=max(ans,t);
    }
    cout << ans;
    return 0; 
} 

```