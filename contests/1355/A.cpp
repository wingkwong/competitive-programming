/*
Codeforces Round #643 (Div. 2) - A. Sequence with Digits
https://codeforces.com/contest/1355/problem/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

long long helper(long long a){
	long long m,minD=10,maxD=0;
	// check each digit and find out the min & max digit
	while(a){
		m=a%10;
		minD=min(minD,m);
		maxD=max(maxD,m);
		a/=10;
	}
	return minD*maxD;
}

int main()  
{ 
    FAST_INP;
    int t;
    long long a,k;
    cin >> t;
    while(t--){
        cin >> a >> k;
        // we only need to calculate the min & max digits for k>2
        // if k=1, a would be the ans
        k--;
        while(k--){
        	long long b = helper(a);
        	// the question states that the minimal and maximal digits in the decimal representation of x without leading zeroes
        	// if it has a leading 0, break it
        	if(b==0) break;
        	// an+minDigit(an)*maxDigit(an)
        	// a: an
        	// b: minDigit(an)*maxDigit(an)
        	a+=b;
		}
        cout << a << "\n";
    }
    return 0;
} 
