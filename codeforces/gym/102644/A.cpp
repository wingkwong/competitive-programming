/*
Matrix Exponentiation - A. Random Mood
https://codeforces.com/gym/102644/problem/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int n;
    double p;
    cin >> n >> p;
    double p1=1.0;
    while(n){
    	if(n&1) p1=p1*(1-p)+(1-p1)*p;
    	p=p*(1-p)+(1-p)*p;
    	n/=2;
	}
	cout << fixed << setprecision(10) << p1 << endl;
    return 0;
} 
