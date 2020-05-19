/*
B - ... (Triple Dots)
https://atcoder.jp/contests/abc168/tasks/abc168_b
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
int main()  
{ 
    FAST_INP;
    int k;
	string s; 
    cin >> k >> s;
    if(s.size()>k) {
    	// print the first k word
    	for(int i=0;i<k;i++) {
    		cout << s[i];
		}
		// and append ... to the ans
		cout << "..." << "\n";
	} else {
		// if the length of S is greater than k
		// print the original value 
		cout << s << "\n";
	}
    return 0;
} 
