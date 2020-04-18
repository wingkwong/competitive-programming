# [Angry Professor](https://www.hackerrank.com/challenges/angry-professor/problem)

A Discrete Mathematics professor has a class of students. Frustrated with their lack of discipline, he decides to cancel class if fewer than some number of students are present when class starts. Arrival times go from on time (arrivalTime <=0) to arrived late (arrivalTime >0).

Given the arrival time of each student and a threshhold number of attendees, determine if the class is canceled.

Sample Input
```
2
4 3
-1 -3 4 2
4 2
0 -1 2 1
```

Sample Output
```
YES
NO
```

Count how many students have arrived on time (the input is negative or zero) and compare with the cancellation threshold ``k``.