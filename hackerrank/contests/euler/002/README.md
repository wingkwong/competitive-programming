# [#002 - Even Fibonacci numbers](https://www.hackerrank.com/contests/projecteuler/challenges/euler002/problem)

Given that the first two Fibonacci numbers are 1 and 2, we can use 3 variables to calculate all Fibonacci numbers in an iterative way in O(n) time complexity with O(1) space complexity. 

```
F[i] = F[i - 2] + F[i - 1]
```

```cpp
while(b <= n) {
    c = a + b;
    a = b;
    b = c; 
}
```

To find out the sum of the even-valued terms, we can check the parity using bitwise operators. 

```cpp
sum += ((b & 1) ^ 1) ? b : 0;
```

As ``n`` can go up to 4 * 10 ^ 16, we have to use ``long long`` to avoid overflow.

Solution:

```cpp
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    int t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        ll sum = 0, a = 1, b = 2, c;
        while(b <= n) {
            sum += ((b & 1) ^ 1) ? b : 0;
            c = a + b;
            a = b;
            b = c; 
        }
        cout << sum << "\n";
    }
    return 0;
}
```
