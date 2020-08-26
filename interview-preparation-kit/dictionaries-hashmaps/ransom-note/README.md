# [Hash Tables: Ransom Note](https://www.hackerrank.com/challenges/ctci-ransom-note/problem)

![image](https://user-images.githubusercontent.com/35857179/81278015-b632f900-9087-11ea-8ce5-618c5f5de14c.png)

Sample Input 0
```
6 4
give me one grand today night
give one grand today
```

Sample Output 0
```
Yes
```

Sample Input 1
```
6 5
two times three is not four
two times two is four
```

Sample Output 1
```
No
```

Put each word in ``magazine`` into a hash map and traverse ``note`` to see if the word occurred in the map or not. If so, deduct the value ``m[s]`` by 1 and continue. If ``m[s]`` reaches 0, it means there is no enough words to build the random note.
