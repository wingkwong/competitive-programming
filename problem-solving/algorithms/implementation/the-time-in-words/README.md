# [The Time in Words](https://www.hackerrank.com/challenges/the-time-in-words/problem)

At minutes=0, use o' clock. For 1 <= minutes <= 30 , use past, and for 30 < minutes use to. Note the space between the apostrophe and clock in o' clock. Write a program which prints the time in words for the input given in the format described.

![image](https://user-images.githubusercontent.com/35857179/79068625-f1494300-7cfa-11ea-9a01-0d58b3e61a77.png)

Sample Input
```
5
47
```

Sample Output
```
thirteen minutes to six
```

Since we need to convert the number to word, we can make a list for the convertion.
```cpp
char nums[][64] = { "zero", "one", "two", "three", "four", 
                    "five", "six", "seven", "eight", "nine", 
                    "ten", "eleven", "twelve", "thirteen", 
                    "fourteen", "fifteen", "sixteen", "seventeen", 
                    "eighteen", "nineteen", "twenty", "twenty one", 
                    "twenty two", "twenty three", "twenty four", 
                    "twenty five", "twenty six", "twenty seven", 
                    "twenty eight", "twenty nine", 
                    }; 

```
We can just list out all the possible cases and select the corresponding numbers.

```
case 1: m==0
case 2: m==1
case 3: m==59
case 4: m==15
case 5: m==30
case 6: m==45
case 7: m<=30
case 8: m>30
```