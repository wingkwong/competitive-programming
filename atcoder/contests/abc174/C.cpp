/*
AtCoder Beginner Contest 174 - C - Repsept
https://atcoder.jp/contests/abc174/tasks/abc174_c
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;

int main()  
{ 
    FAST_INP;
    // use modular arithmetic to find the remainders 
    // and check if the val is 0, which means it can divided by k
    int k;
    cin >> k;
	int val=7%k;
	for(int i=1;i<1e7;i++){
		if(val==0){
			cout << i << endl;
			return 0;
		}
		val=(val*10+7)%k;
	}
	cout << "-1" << endl;
    return 0;
} 
