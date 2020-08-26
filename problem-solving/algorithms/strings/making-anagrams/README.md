# [Making Anagrams](https://www.hackerrank.com/challenges/making-anagrams/problem)

We consider two strings to be anagrams of each other if the first string's letters can be rearranged to form the second string. In other words, both strings must contain the same exact letters in the same exact frequency. For example, bacdc and dcbac are anagrams, but bacdc and dcbad are not.

Alice is taking a cryptography class and finding anagrams to be very useful. She decides on an encryption scheme involving two large strings where encryption is dependent on the minimum number of character deletions required to make the two strings anagrams. Can you help her find this number?

Given two strings, s1 and s2, that may not be of the same length, determine the minimum number of character deletions required to make  and  anagrams. Any characters can be deleted from either of the strings.

For example, s1 = abc and s2=amnop . The only characters that match are the a's so we have to remove bc from s1 and mnop from s2 for a total of 6 deletions.

Sample Input
```
cde
abc
```

Sample Output
```
4
```

Explanation
```
We delete the following characters from our two strings to turn them into anagrams of each other:

Remove d and e from cde to get c.
Remove a and b from abc to get c.
We had to delete  characters to make both strings anagrams.
```

Let's say 
```
s1: aaaaaabc
s2: aaaaabbc
r : aaaaabc
```

and if we break it down 
```
s1            | a:6 b:1 c:1
s2            | a:5 b:2 c:1
expected      | a:5 b:1 c:1
to-be-deleted | a:1 b:1 c:0
```

We can easily find the pattern so that we know how many and which letters we need to delete. For each letter, the pattern is 
```
|s1(n)-s2(n)|
```

We need the absolute value or else we will get a negative value and make the calculation wrong. At the end, sum them up and output it.

Read two inputs ``s1`` and ``s2``. 

For each letter,
```cpp
for(int c='a';c<='z';++c)
```

we can use ``count`` to find out the occurrence of the letter 
```cpp
// for s1
count(s1.begin(),s1.end(),c)
// for s2
count(s2.begin(),s2.end(),c))
```

use ``abs`` to return the absolute value 

Final Solution:
```cpp
string s1,s2;
int r=0;

int main()  
{ 
    FAST_INP;

    cin >> s1 >> s2;
    for(int c='a';c<='z';++c){
        r+=abs(count(s1.begin(),s1.end(),c) - count(s2.begin(),s2.end(),c));
    }
    cout << r;
    return 0; 
}
```