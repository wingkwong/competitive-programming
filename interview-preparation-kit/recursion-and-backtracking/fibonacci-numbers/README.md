# [Fibonacci Numbers](https://www.hackerrank.com/challenges/ctci-fibonacci-numbers/problem)

![image](https://user-images.githubusercontent.com/35857179/81569330-b86fbd00-93d1-11ea-829e-4168d3abd6e0.png)

Sample Input
```
3  
```

Sample Output
```
2
```

This is a classical question. We can obverse that fibonacci(0) is 0, fibonacci(1) is 1, fibonacci(2) is 1, and starting from ``n=3``, fibonacci(n)=fibonacci(n-1)+fibonacci(n-2). It goes like 0,1,1,2,3,5,8 and so on. 

```cpp
int fibonacci(int n) {
    if(n==0) return 0;
    if(n==1||n==2) return 1;
    return fibonacci(n-1)+fibonacci(n-2);
}
```

However, if we use this approach, there will be lots of repeating process. For example, fibonacci(4)=fibonacci(3)+fibonacci(2) and fibonacci(3)=fibonacci(2)+fibonacci(1). We can see that fibonacci(2) is duplicate as well as it branches such as fibonacci(1) and fibonacci(0) in this case. Therefore, we can implement Memoization here.

Memoization is an optimization technique to speed up by storing the results of function calls. If we need to call the function, and the function has been called before, we can simply just take the result.

To do that, we can initialise a vector with a value of 0.

```cpp
vector<int> memo(n+1,0);
```

Then we know that our first three fibonacci numbers are 0, 1 and 1. We can set them first.

```cpp
memo[0]=0;
memo[1]=memo[2]=1;
```

If fibonacci(n) has been calculated, we can return the result immediately. If not, calculate it and return memo[n] afterwards.  
```cpp
if(memo[n]) return memo[n];
memo[n] = f(n-1,memo)+f(n-2,memo);
return memo[n];
```
