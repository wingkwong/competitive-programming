# [Comparator](https://www.hackerrank.com/challenges/ctci-comparator-sorting/problem)

![image](https://user-images.githubusercontent.com/35857179/81497371-a702b400-92f0-11ea-857a-edc64fcba616.png)

Sample Input
```
5
amy 100
david 100
heraldo 50
aakansha 75
aleksa 150
```

Sample Output
```
aleksa 150
amy 100
david 100
aakansha 75
heraldo 50
```

Sort the score first, then sort the name.

Final Solution
```cpp
class Checker{
public:
    static int comparator(Player a, Player b)  {
        if(a.score>b.score) return 1;
        if(a.score<b.score) return -1;
        if(a.name<b.name) return 1;
        return -1;
    }
};
```