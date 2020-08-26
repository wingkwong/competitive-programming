/*
ONP - FCTRL2 - Small factorials
https://www.spoj.com/problems/FCTRL2/
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 

void solve(int n){
//	The factorial of the integer n, written n!, is defined as:
//
//	```
//	n! = n * (n-1) * (n-2) * ... * 3 * 2 * 1
//	```
//	
//	Calculate and print the factorial of a given integer.
//	
//	But for N > 20, this value becomes quite large and doesn't fit even in a 64 bit long long variable. Languages like Java, Python, Ruby etc. provide support for Big Integers. We can solve this problem easily in these languages by using the Big integer libraries provided.
//	But in C / C++, we need to write additional code to handle big integer values. In the simplest form, we can store the factorials in an array with one digit at each index of the array.
//	
//	For example : To store 245 in the array,
//	```
//	a[2]=2
//	a[1]=4
//	a[0]=5
//	```
//	
//	To multiply a number say i to this value, we start off from the index 0 of the array. At every iteration, we calculate i * a[index]. We also maintain a carry from the previous index which is initialized to 0. Now, at every step, we calculate product = a[index] * i + c. The new value of a[index] will be product % 10 and the new value of carry will be product/10. We propogate this carry to higher order digits.

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
    for(int i=s-1;i>=0;i--) cout << a[i];
    cout << endl;
}

int main()  
{ 
    FAST_INP;
    int t,n;
    cin >> t;
    while(t--){
    	cin >> n;
		solve(n);
    }
    return 0;
}
