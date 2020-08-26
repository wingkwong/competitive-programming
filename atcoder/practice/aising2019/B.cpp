/*
AISing Programming Contest 2019 - B - Contests
https://atcoder.jp/contests/aising2019/tasks/aising2019_b
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
int main()  
{ 
    FAST_INP;
    int n,a,b,p,s1=0,s2=0,s3=0;
    cin >> n >> a >> b;
    for(int i=0;i<n;i++) {
    	cin >> p;
    	if(p<=a) s1++;
    	else if(a+1<=p&&p<=b) s2++;
    	else if(p>=b+1) s3++;
	}
	
	cout << min({s1,s2,s3});
    return 0;
} 

// 1st: <= A
// 2nd: A+1 <= s <= B
// 3rd: s >= B+1
