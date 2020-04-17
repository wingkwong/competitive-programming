# [Breaking the Records](https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem)

Maria plays college basketball and wants to go pro. Each season she maintains a record of her play. She tabulates the number of times she breaks her season record for most points and least points in a game. Points scored in the first game establish her record for the season, and she begins counting from there.

For example, assume her scores for the season are represented in the array scores = [12,24,10,24] . Scores are in the same order as the games played. She would tabulate her results as follows:
```
                                 Count
Game  Score  Minimum  Maximum   Min Max
 0      12     12       12       0   0
 1      24     12       24       0   1
 2      10     10       24       1   1
 3      24     10       24       1   1
 ```

Given Maria's scores for a season, find and print the number of times she breaks her records for most and least points scored during the season.

Sample Input
```
9
10 5 20 20 4 5 2 25 1
```

Sample Output 
```
2 4
```

Loop through each score and check if it is higher / lower the highest score / lowest score. If so, update the value and increase the corresponding counter.