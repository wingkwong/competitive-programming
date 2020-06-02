# [#001 - Multiples of 3 and 5](https://www.hackerrank.com/contests/projecteuler/challenges/euler001/problem)

If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3,5,6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below N.

Sample Input 
```
2
10
100
```

Sample Output
```
23
2318
```

To sum from 1 to i, it is

```
s=1+2+3...+(i-1)+i
```

if you reverse the order
```
s=1+2+3...+(i-1)+i
s=i+(i-1)+(i-2)+...+2+1
```

summing each value, we got
```
2s=(i+1)+(i+1)+...(i+1)+(i+1)
```

and there are ``i`` ``(i+1)`` in above formula

```
2s=i(i+1)
```

at the end, we got 

```
s=i(i+1)/2
```

We can use ``s=i(i+1)/2`` to caculate the sum from 1 to ``i``. However, the question just needs us to calculate the sum of the multiples of 3 or 5. 

Take 3 as an example
```
s=3+6+9+...+3i
s=3(1+2+3+...+i)
```

We know that ``1+2+3+...+i`` can be calculated using ``s=i(i+1)/2``. Therefore, we now know 

```
s=3(1+2+3+...+i)
s=3(i(i+1)/2)
```

where 
```
3i <= n
i <= n/3 
```

it becomes

```
s=n((n/k)((n/k)+1)/2)
```

The question states that it only requires the multiples of K below N, that means it does not include N, hence we should substract N from 1.

However, if we sum up multiples of 3 and multiples of 5, we can get duplicate values, i.e. 15 in below example
```
multiples of 3: 3,6,9,15,18...
multiples of 5: 5,10,15,20,...
```

Hence, we need to subtract the series of their least common multiple (LCM) which is 15. The final answer is 

```
S(3) + S(5) - S(15)
```

Final Solution:
```cpp
ll t,i,x;

ll s(ll n,ll k){
    x = n/k;
    return (k*(x*(x+1)))/2;
}

int main()  
{ 
    FAST_INP;

    cin >> t;
    TC(t){
        cin >> i;
        cout << s(i-1,3)+s(i-1,5)-s(i-1,15) << "\n";
    }
    return 0; 
}
```