```cpp
double ans=1;
while(n!=0){
    // if n is odd, a^n can be seen as a^(n/2) * a^(n/2) * a
    if(n&1) ans*=x;
    // if n is even, a^n can be seen as a^(n/2) * a^(n/2)
    x*=x;
    n/=2;
};
```