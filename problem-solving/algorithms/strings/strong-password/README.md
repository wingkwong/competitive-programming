# [Strong Password](https://www.hackerrank.com/challenges/strong-password/problem)

Louise joined a social networking site to stay in touch with her friends. The signup page required her to input a name and a password. However, the password must be strong. The website considers a password to be strong if it satisfies the following criteria:

Its length is at least 6.
It contains at least one digit.
It contains at least one lowercase English character.
It contains at least one uppercase English character.
It contains at least one special character. The special characters are: !@#$%^&*()-+
She typed a random string of length  in the password field but wasn't sure if it was strong. Given the string she typed, can you find the minimum number of characters she must add to make her password strong?

Note: Here's the set of types of characters in a form you can paste in your solution:

```
numbers = "0123456789"
lower_case = "abcdefghijklmnopqrstuvwxyz"
upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
special_characters = "!@#$%^&*()-+"
```

Sample Input
```
3
Ab1
```

Sample Output
```
3
```

Explanation 
```
She can make the password strong by adding 3 characters, for example, $hk, turning the password into Ab1$hk which is strong.
2 characters aren't enough since the length must be at least 6.
```

Read ``n`` and loop ``n`` times to read each letter ``c``. 

Make 5 variables to hold if each condition is fulfilled or not.

```
l  ->    Its length is at least 6.
d  ->    It contains at least one digit.
lc ->    It contains at least one lowercase English character.
uc ->    It contains at least one uppercase English character.
sc ->    It contains at least one special character. The special characters are: !@#$%^&*()-+
```

Initialise all 5 variables to ``0``. Set it to ``1`` if the condition is fulfilled. 

We also need another variable ``x`` to store the number of conditions that are not fulfilled except the first condition.  

For example, Ab1 does not contain at least one special character. Hence, ``x`` is 1. 

```
Ab1
l  d  lc uc sc x
0  1  1  1  0  1
```

Imagine if the length of the input is at least 6, we can simply add 1 special character for this case. If ``x`` is 2, we can add two. Therefore, for ``l=1`` case, we need to add ``x`` characters. 

However, if the length of the input is less than 6, we need to add at least ``6-n`` characters. 

This does not cover all cases. Let's say ``n`` is 4 while x is ``4`` We cannot just add 2 characters to cover 4 cases. Therefore, for ``l=1``, we need to add ``max(x, 6-n)`` characters.

Final Solution:
```cpp
int n,x,l,d,lc,uc,sc;
char c;

int main()  
{ 
    FAST_INP;

    cin >> n;
    x=l=d=lc=uc=sc=0;
    if(n>=6) l=1;
    REP(i,n){
        cin >> c;
        if(isdigit(c)) d=1;
        else if(islower(c)) lc=1;
        else if(isupper(c)) uc=1;
        else if(c=='!'||c=='@'||c=='#'||c=='$'||c=='%'||c=='^'||c=='&'||c=='*'||c=='('||c==')'||c=='-'||c=='+') sc=1;
    }

    if(!d)++x;
    if(!lc)++x;
    if(!uc)++x;
    if(!sc)++x;

    // cout << l << " " << d << " " << lc << " " << uc << " " << sc << " " << x << "\n";

    // 3
    // Ab1
    // 0 1 1 1 0 1

    // 11
    // #HackerRank
    // 1 0 1 1 1 1

    // 8
    // zC9!Xx56
    // 1 1 1 1 1 0
    
    if(!l) cout << max(x, 6-n);
    else  cout << x;
        
    return 0; 
} 
```