# [Grading Students](https://www.hackerrank.com/challenges/grading/problem)

HackerLand University has the following grading policy:

Every student receives a grade in the inclusive range from 0 to 100.
Any grade less than 40 is a failing grade.
Sam is a professor at the university and likes to round each student's grade according to these rules:

If the difference between the grade and the next multiple of 5 is less than 3, round grade up to the next multiple of 5.
If the value of grade is less than 38, no rounding occurs as the result will still be a failing grade.
For example, grade=84 will be rounded to 85 but grade=29 will not be rounded because the rounding would result in a number that is less than 40.

Given the initial value of grade for each of Sam's n students, write code to automate the rounding process.

Sample Input 
```
4
73
67
38
33
```

Sample Output
```
75
67
40
33
```

The question states that there is no rounding if the value of grade is less than 38. We can print the input directly for this case.
```cpp
if(s>=38){
    // TODO
}
cout << s <<"\n";
```

If it is greater than or equal to 38, we need to find out the diff between the input and the next multiple of 5. 
```cpp
d=5-(s%5);
```

Check if the diff is less than 3, if so, add it to the input
```cpp
if(d<3) s+=d;
```