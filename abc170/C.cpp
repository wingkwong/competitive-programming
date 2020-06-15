/*
AtCoder Beginner Contest 170 - C - Forbidden List
https://atcoder.jp/contests/abc170/tasks/abc170_c
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
int main()  
{ 
    FAST_INP;
    int x,n;
    cin >> x >> n;
	// if n is 0, x is the answer
    if(n==0){
    	cout << x << endl;
    	return 0;
	}
	vector<int> p(n);
	// read p1..pn
	for(int i=0;i<n;i++){
		cin >> p[i];
	}
	// brute force approach - look for values smaller than / equal to x
	int l=0,r=0;
	// check each value which has the minimum absolute difference with X 
	// x is also a possible ans
	for(int k=x;k>=0;k--){
		int f=1;
		// and the value is not in p1..pn
		for(int i=0;i<n;i++){
			if(k==p[i]){
				f=0;
				break;
			}
		}
		if(f) {
			l=k;
			break;
		}
	}
	// brute force approach - look for values greater than / equal to x
	for(int k=x;k<=100;k++){
		int f=1;
		for(int i=0;i<n;i++){
			if(k==p[i]){
				f=0;
				break;
			}
		}
		if(f) {
			r=k;
			break;
		}
	}
	
	// find out which one is smaller
	// if they are equal, take the smaller number
	if(x-l<=r-x){
		cout << l << endl;
	} else {
		cout << r << endl;
	}
    return 0;
} 


