# [Camel Case](https://www.hackerrank.com/challenges/camelcase/problem)

Alice wrote a sequence of words in CamelCase as a string of letters,s, having the following properties:

It is a concatenation of one or more words consisting of English letters.
All letters in the first word are lowercase.
For each of the subsequent words, the first letter is uppercase and rest of the letters are lowercase.
Given , print the number of words in  on a new line.

For example, s=oneTwoThree. There are 3 words in the string.

Sample Input
```
saveChangesInTheEditor
```

Sample Output
```
5
```

Explanation

String  contains five words:
```
save
Changes
In
The
Editor
Thus, we print 5 on a new line.
```

Read an input ``s`` and loop each character. If it is in upper case, add ``cnt`` by 1. Output the ``cnt`` at the end.

Final Solution:
```cpp
int cnt=1; string s;

int main()  
{ 
    FAST_INP;

    cin >> s;
    REP(i,s.size()){
        if(isupper(s[i])) cnt++;
    }
    cout << cnt;
    return 0; 
} 
```