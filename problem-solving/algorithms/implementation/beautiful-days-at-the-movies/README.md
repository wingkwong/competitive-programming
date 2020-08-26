# [Beautiful Days at the Movies](https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem)

Lily likes to play games with integers. She has created a new game where she determines the difference between a number and its reverse. For instance, given the number 12, its reverse is 21. Their difference is 9. The number 120 reversed is 21, and their difference is 99.

She decides to apply her game to decision making. She will look at a numbered range of days and will only go to a movie on a beautiful day.

Given a range of numbered days, [i...j] and a number k, determine the number of days in the range that are beautiful. Beautiful numbers are defined as numbers where |i-reverse(i)| is evenly divisible by k. If a day's value is a beautiful number, it is a beautiful day. Print the number of beautiful days in the range.

Sample Input
```
20 23 6
```

Sample Output
```
2
```

Loop from ``i`` to ``j`` inclusively, calcute its reversed number.

A simple way to reverse a number is to declare a temp variable initialized to 0 
```cpp
int rn=0;
```

and get each digit
```cpp
r=n%10;
```

Add it to ``rn``*10
```cpp
rn=rn*10+r;
```

Repeat it until n becomes 0
```cpp
while(n){
//...
n/=10;
}
```

For example, the number ``20``, the first digit is ``0``.
```
rn=0*10+0
```

the second digit is 2
```
rn=0*10+2
```

so the reversed number of ``20`` is ``2``.

Then, we can apply |i-reverse(i)|%k to see if it is 0, meaning it is evenly divisible by ``k``. If so, increase the counter by 1 and print the output at the end.
