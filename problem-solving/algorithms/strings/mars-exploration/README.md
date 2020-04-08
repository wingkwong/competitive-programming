# [Mars Exploration](https://www.hackerrank.com/challenges/mars-exploration/problem)

Letters in some of the SOS messages are altered by cosmic radiation during transmission. Given the signal received by Earth as a string,s, determine how many letters of Sami's SOS have been changed by radiation.

For example, Earth receives SOSTOT. Sami's original message was SOSSOS. Two of the message characters were changed in transit.

Sample Input
```
SOSSPSSQSSOR
```

Sample Output
```
3
```

Explanation
s = SOSSPSSQSSOR, and signal length |s|=12 . Sami sent 4 SOS messages (i.e.: 12/3=4).

Expected signal: SOSSOSSOSSOS
Recieved signal: SOSSPSSQSSOR
Difference:          X  X   X

Read an input ``s`` and loop ``s`` times. Check each character if it matches the expected character. 

```
1n character should match the character "S"
2n character should match the character "O"
3n character should match the character "S"
```

where n starts from ``1`` to ``|s|/3``

We can declare a string ``SOS`` and get the expected character by using ``sos[i%3]``. If it does not match, increase ``cnt`` by 1. Print ``cnt`` at the end.

Final Solution
```cpp

string s;
string sos="SOS";
int cnt=0;

int main()  
{ 
    FAST_INP;
    
    cin >> s;
    REP(i,s.size()){
       if(s[i]!=sos[i%3])cnt++;
    }
    cout << cnt;
    return 0; 
} 
```