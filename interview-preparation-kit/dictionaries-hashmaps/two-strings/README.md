# [Two Strings](https://www.hackerrank.com/challenges/two-strings/problem)

![image](https://user-images.githubusercontent.com/35857179/80808449-2e19a300-8bf2-11ea-8396-0273b23e9387.png)

Sample Input
```
2
hello
world
hi
world
```

Sample Output
```
YES
NO
```

To do this, we can create a set ``s`` where contains the unique characters in the string. Traverse the other string to see if it appears in the set. 

```cpp
string twoStrings(string s1, string s2) {
    set<char> s;
    // insert each character into a set
    for(char c : s1) if(!s.count(c)) s.insert(c);
    // if a character in s2 is found in a set, return immediately
    for(char c : s2) if(s.count(c)) return "YES"; 
    return "NO";
}
```