# [Pangrams](https://www.hackerrank.com/challenges/pangrams/problem)

Roy wanted to increase his typing speed for programming contests. His friend suggested that he type the sentence "The quick brown fox jumps over the lazy dog" repeatedly. This sentence is known as a pangram because it contains every letter of the alphabet.

After typing the sentence several times, Roy became bored with it so he started to look for other pangrams.

Given a sentence, determine whether it is a pangram. Ignore case.

Sample Input 0
```
We promptly judged antique ivory buckles for the next prize
```

Sample Output 0
```
pangram
```

Sample Explanation 0
```
All of the letters of the alphabet are present in the string.
```

Sample Input 1
```
We promptly judged antique ivory buckles for the prize
```

Sample Output 1
```
not pangram
```

Sample Explanation 0
```
The string lacks an x.
```

Read a string ``s`` and loop ``s.size()`` times. We need to know if each letter exists in ``s``. However, the input may contains ``a-z, A-Z, space``, we need to convert it to lower case so that we can only use an array of 26 to solve this problem. 

For example, if character ``a`` is found, we set a[0]=1, if character ``b`` is found, we set a[1]=1, and so on. Now we know each letter matches an index as below. 
```
abcdef...z
012345...26
```

To find out which index to be used, we can use ASCII code. If you check out the table [here](http://www.asciitable.com/), you should see the decimal of the letter ``a`` is ``97``, and ``b`` is ``98`` and so on. Hence, we can convert a character to an integer, which is the ASCII decimal of the letter, and subtracts ``97`` from it so that we can have the abovementioned index. 

```cpp
k=(int)tolower(s[i])-97;
```

Since it may include spaces, and the decimal of the space is ``32``. Hence, we need to take care of this case. If it is a space, you will get a negative value (32-97). We only need to set the value to ``1`` for ``a[i]`` if ``k`` is less than ``0`` and ``a[i]`` is ``0``. At the end, print out whether it is ``pangram`` or ``not pangram`` based on ``cnt``. 

Final Solution
```cpp

string s;
int a[26]={0},k,cnt=0;

int main()  
{ 
    FAST_INP;
  
    getline(cin, s);
    REP(i,s.size()){
        k=(int)tolower(s[i])-97;
        if(k>=0 && a[k]==0) {
            ++a[k];
            ++cnt;
        }
    }
    cout << (cnt==26?"pangram":"not pangram") << "\n";
    return 0; 
} 
```