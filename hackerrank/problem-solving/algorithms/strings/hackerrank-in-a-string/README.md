# [HackerRank in a String](https://www.hackerrank.com/challenges/hackerrank-in-a-string/problem)

We say that a string contains the word hackerrank if a subsequence of its characters spell the word hackerrank. For example, if string s=haacckkerrannkk it does contain hackerrank, but s=haacckkerannk does not. In the second case, the second r is missing. If we reorder the first string as hccaakkerrannkk , it no longer contains the subsequence due to ordering.

More formally, let p[0], p[1],...,p[9] be the respective indices of h, a, c, k, e, r, r, a, n, k in string . If s is true, then p[0]<p[1]<p[2]< ... <p[9] contains hackerrank.

For each query, print YES on a new line if the string contains hackerrank, otherwise, print NO.

Sample Input
```
2
hereiamstackerrank
hackerworld
```

Sample Output
```
YES
NO
```

Read an input ``n`` and loop ``n`` times. Read another input ``s`` and loop ``s.size()`` times to check if the characher ``s[j]`` is equal to ``h[k]`` where ``h`` is the string ``hackerrank`` and ``k`` is the index of the character being checked starting from 0. If it matches, increase ``k`` by 1. At the end, if ``s`` contains ``hackerrank``, ``k`` must be ``10``. Hence, print ``YES`` if so and ``NO`` if not.

Final Solution
```cpp
int n,k;
string s,h="hackerrank";

int main()  
{ 
    FAST_INP;
    
    cin >> n;
    REP(i,n){
      cin >> s;
      k=0;
      REP(j, s.size()) {
          if(s[j]==h[k])k++;
      }
      cout << (k==10?"YES":"NO") << "\n";
    }
    
    return 0; 
} 
```