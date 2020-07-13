/*
Help Oz
https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/a-simple-task/

Oz has a list arr[] of M integers. He has to find all integers K such that :

1) K > 1
2) arr[1]%K = arr[2]%K = arr[3]%K = ... = arr[M]%K where '%' is a modulus operator
Help Oz to find all such K's.

Input :
First line of input contains an integer M. Then M lines follow each containing one integer of the list. Input data is such that at least one integer K will always exist.

Output :
Output all possible integers K separated by space in increasing order.

Constraints :
- 2<= M <=100
- 1< value of each integer <109
- All integers will be distinct
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
int main()  
{ 
    FAST_INP;
    // approach: 
    // (a+d)%k = a%k
    // a%k + d%k = a%k 
    // d%k = 0
    int t;
	cin >> t;
	vector<int> a(t), v, ans;
	int mx=INT_MIN, mi=INT_MAX;
	for(int i=0;i<t;i++) {
		cin >> a[i];
		mx=max(a[i],mx);
		mi=min(a[i],mi);
	}
	int d = mx - mi;
    // find out all the divisors of d
	for(int i=1;i*i<=d;i++){
		if(d%i==0){
			v.emplace_back(i);
			if(d/i!=i){
				v.emplace_back(d/i);
			}
		}
	}
    // check if the mod is same or not
	for(int i=0;i<(int)v.size();i++){
		int tmp = a[0]%v[i];
		int j;
		for(j=1;j<t;j++){
			if(a[j]%v[i]!=tmp) break;
		}
		if(v[i]>1&&j==t) ans.emplace_back(v[i]);
	}
    // display it in increasing order
	sort(ans.begin(), ans.end());
	for (auto k : ans) cout << k << " ";
    return 0;
}  
