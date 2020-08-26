# [Find Digits](https://www.hackerrank.com/challenges/find-digits/problem)

An integer d is a divisor of an integer n if the remainder of n/d = 0.

Given an integer, for each digit that makes up the integer determine whether it is a divisor. Count the number of divisors occurring within the integer.

Note: Each digit is considered to be unique, so each occurrence of the same digit should be counted (e.g. for n=111 , 1 is a divisor of 111 each time it occurs so the answer is 3).

Sample Input
```
2
12
1012
```

Sample Output
```
2
3
```

Explanation

The number 12 is broken into two digits, 1 and 2. When 12 is divided by either of those two digits, the remainder is 0 so they are both divisors.

The number 1012 is broken into four digits,1,0,1 and 2. 1012 is evenly divisible by its digits 1,1, and 2, but it is not divisible by 0 as division by zero is undefined.

Store the input to ``mm`` first because ``n`` will be updated
```cpp
nn=n;
```

For this kind of questions, we have below structure
```cpp
while(n){
    // get the last digit
    // do something
    // divide n by 10
}
```

Get the last digit ``m`` of the input ``n``
```cpp
m=n%10;
```

Divide the input by ``m`` to check if the remainder is ``0``. If so, increase ``ans`` by 1. We only do it when ``m`` is non-zero. 
```cpp
if(m&&nn%m==0) ans++;
```

Update ``n``. Simple divide by 10 to handle the next digit for the next loop
```cpp
n/=10;
```

```cpp
1012 
n%10 -> 2 
1012%2 = 0 // increase ans by 1
101 // divided by 10
----
n%10 -> 1 
101%1 = 0 // increase any by 1
10 // divided by 10
----
n%10 -> 0 // skip
1 // divided by 10
----
n%10 -> 1 
1%1 = 0 // increase any by 1
----
ans = 3 
```
