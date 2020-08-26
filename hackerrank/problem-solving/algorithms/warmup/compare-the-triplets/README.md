# [Compare the Triplets](https://www.hackerrank.com/challenges/compare-the-triplets/problem)

Alice and Bob each created one problem for HackerRank. A reviewer rates the two challenges, awarding points on a scale from 1 to 100 for three categories: problem clarity, originality, and difficulty.

If a[i] > b[i], then Alice is awarded 1 point.
If a[i] < b[i], then Bob is awarded 1 point.
If a[i] = b[i], then neither person receives a point.

Sample Input 
```
5 6 7
3 6 10
```

Sample Output
```
1 1
```
We just need to read 6 integer and focus on ``a[i]>b[i]`` and ``b[i]>a[i]`` cases only as ``a[i]=b[i]`` gives 0 point.
