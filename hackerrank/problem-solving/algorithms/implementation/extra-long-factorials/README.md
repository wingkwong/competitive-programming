# [Extra Long Factorials](https://www.hackerrank.com/challenges/extra-long-factorials/problem)

The factorial of the integer n, written n!, is defined as:

```
n! = n * (n-1) * (n-2) * ... * 3 * 2 * 1
```

Calculate and print the factorial of a given integer.

But for N > 20, this value becomes quite large and doesn't fit even in a 64 bit long long variable. Languages like Java, Python, Ruby etc. provide support for Big Integers. We can solve this problem easily in these languages by using the Big integer libraries provided.
But in C / C++, we need to write additional code to handle big integer values. In the simplest form, we can store the factorials in an array with one digit at each index of the array.

For example : To store 245 in the array,
```
a[2]=2
a[1]=4
a[0]=5
```

To multiply a number say i to this value, we start off from the index 0 of the array. At every iteration, we calculate i * a[index]. We also maintain a carry from the previous index which is initialized to 0. Now, at every step, we calculate product = a[index] * i + c. The new value of a[index] will be product % 10 and the new value of carry will be product/10. We propogate this carry to higher order digits.


Final Solution
```cpp
int n,a[200],s=1,c,p;

int main()  
{ 
    FAST_INP;
    cin >> n;
    a[0]=1;
    FORN(i,2,n){
        c=0;
        REP(j,s){
            p=a[j]*i+c;
            a[j]=p%10;
            c=p/10;
        }
        while(c){
            a[s]=c%10;
            c/=10;
            s++;
        }
    }
    FORD(k,s-1,0) cout << a[k];
    return 0; 
} 
```

## Reference:
https://www.geeksforgeeks.org/factorial-large-number/