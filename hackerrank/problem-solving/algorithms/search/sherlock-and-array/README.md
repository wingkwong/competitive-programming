# [Sherlock and Array](https://www.hackerrank.com/challenges/sherlock-and-array/problem)

![image](https://user-images.githubusercontent.com/35857179/80174074-30916100-8624-11ea-92b3-6e44ff33543f.png)

Sample Input
```
2
3
1 2 3
4
1 2 3 3
```

Sample Output
```
NO
YES
```

5,6,8,11 -> 30
v[0]: 5
v[1]: 6
v[2]: 8
v[3]: 11

Given ``N`` element in an array, we know the sum is 
```
sum = A1+A2+A3+..+AN 
```

We can return YES for the following case 
```
sum-A1-A2-AI = AN
```

To do that, we calcuclate the sum of all elements first and travese the array to find out if the above condition is true or not. If not, we add the current value to a variable ``l`` which stores the sum of the elements at the current index. 


If we see N=1, we can directly return YES.  


Final Solution
```cpp
int t,n,sum,f,l;
int main()  
{ 
    FAST_INP;
    cin >> t;
    TC(t){
        f=0;
        cin >> n;
        vi v(n);
        REP(i,n) cin >> v[i];
        // case: 1
        if(n==1) f=1;
        else {
            sum=accumulate(v.begin(),v.end(),0);
            l=v[0];
            // case: 2 0 0 0
            if(sum-l==0) f=1;
            else{
                FOR(i,1,n){
                    if(sum-v[i]-l==l||sum-v[i]==0){
                        f=1;
                        break;
                    }
                    l+=v[i];
                }
            }
        }   
        if(f) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0; 
} 
```