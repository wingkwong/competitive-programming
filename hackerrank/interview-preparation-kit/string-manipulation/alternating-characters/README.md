# [Alternating Characters](https://www.hackerrank.com/challenges/alternating-characters/problem)

![image](https://user-images.githubusercontent.com/35857179/81497052-8b96a980-92ee-11ea-92ab-d4a9bdbe568b.png)

Sample Input
```
5
AAAA
BBBBB
ABABABAB
BABABA
AAABBB
```

Sample Output
```
3
4
0
0
4
```

Since we only have two different character ``A`` and ``B``, we can take the first one as ``c`` and iterate the rest of them to compare with it. If they are same, increase the counter by 1. If not, update ``c`` to the other character.

Final Solution
```cpp
int alternatingCharacters(string s) {
    int ans=0;
    char c=s[0];
    for(int i=1;i<s.size();i++){
        char cc=s[i];
        if(c==cc) ans++;
        else c=cc;
    }
    return ans;
}
```