/*
Small factorials Problem Code: FCTRL2

You are asked to calculate factorials of some small positive integers.

Input
An integer t, 1<=t<=100, denoting the number of testcases, followed by t lines, each containing a single integer n, 1<=n<=100.

Output
For each integer n given at input, display a line with the value of n!

Example
Sample input:
4
1
2
5
3
Sample output:

1
2
120
6
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

// The factorial of the integer n, written n!, is defined as:

// n! = n * (n-1) * (n-2) * ... * 3 * 2 * 1
// Calculate and print the factorial of a given integer.

// But for N > 20, this value becomes quite large and doesn't fit even in a 64 bit long long variable. 
// Languages like Java, Python, Ruby etc. provide support for Big Integers. 
// We can solve this problem easily in these languages by using the Big integer libraries provided. 
// But in C / C++, we need to write additional code to handle big integer values. 
// In the simplest form, we can store the factorials in an array with one digit at each index of the array.

// For example : To store 245 in the array,

// a[2]=2
// a[1]=4
// a[0]=5
// To multiply a number say i to this value, we start off from the index 0 of the array. 
// At every iteration, we calculate i * a[index]. 
// We also maintain a carry from the previous index which is initialized to 0. 
// Now, at every step, we calculate product = a[index] * i + c. 
// The new value of a[index] will be product % 10 and the new value of carry will be product/10. 
// We propogate this carry to higher order digits.

void f(int n){
    int a[200],s=1,c,p;
    a[0]=1;
    for(int i=2;i<=n;i++){
        c=0;
        for(int j=0;j<s;j++){
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
    for(int k=s-1;k>=0;k--) {
        cout << a[k];
    }
    cout << "\n";
}

int main()  
{ 
    FAST_INP;
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        f(n);
    }
    return 0;
} 


// for N < 20, you may use below approach
// ----------------------------------

// #include <bits/stdc++.h>
// using namespace std; 

// #define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

// int m[105]={0};

// int f(int n){
//     // f(1) -> 1
//     // f(2) -> 2*f(1) 
//     // f(3) -> 3*f(2) 
//     // f(n) -> n*f(n-1)
//     if(m[n]) return m[n];
//     if(n==1) return 1;
//     m[n]=n*f(n-1);
//     return m[n];
// }

// int main()  
// { 
//     FAST_INP;
//     int t,n;
//     cin >> t;
//     while(t--){
//         cin >> n;
//         cout << f(n) << "\n";
//     }
//     return 0;
// } 