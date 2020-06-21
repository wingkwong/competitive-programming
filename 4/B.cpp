/*
Codeforces Beta Round #4 (Div. 2 Only) - B. Before an Exam
https://codeforces.com/problemset/problem/4/B
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int d,x,sumTime,minTime[30],maxTime[30],s1=0,s2=0;
    cin >> d >> sumTime;
	// if it is YES, it should fulfil below requirement 
	// sum(minTime) <= sumTime <= sum(maxTime)
    for(int i=0;i<d;i++){
    	cin >> minTime[i] >> maxTime[i];
    	s1+=minTime[i];
    	s2+=maxTime[i];
	}
	// greedy method to construct a list  
	if(s1<=sumTime&&sumTime<=s2) {
		cout << "YES\n";
		for(int i=0;i<d;i++){
			x=min(maxTime[i],sumTime-s1+minTime[i]);
			cout << x << " ";
			sumTime-=x;
			s1-=minTime[i];
		}
	}
	else cout << "NO\n";
    return 0;
} 
