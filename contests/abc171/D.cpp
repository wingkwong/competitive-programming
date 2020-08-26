/*
AtCoder Beginner Contest 171 - D - Replacing
https://atcoder.jp/contests/abc171/tasks/abc171_d
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
int main()  
{ 
    FAST_INP;
    long long n,a,b,c,q,sum=0;
    set<long long> num;
    map<long long,long long> m;
    cin >> n;
    for(int i=0;i<n;i++){
    	cin >> a;
		// store into set to know how many distinct numbers
		num.insert(a);
		// store into map to know the occurrences of this number
		m[a]++;
		// pre-calculate the initial sum
		sum+=a;
	}
	cin >> q;
	for(int i=0;i<q;i++){
		// read b & c - replace all b by c 
		cin >> b >> c;
		// there are m[b] numbers for b, the sum of them is m[b]*b
		// by removing m[b] numbers, the sum is deducted 
		sum-=(m[b]*b);
		// removing m[b] numbers from b means adding m[c] numbers to c
		m[c]+=m[b];
		// update the sum
		sum+=(m[b]*c);
		// remove all b, m[b] becomes 0
		m[b]=0;
		cout << sum << endl;
	}
    return 0;
} 

// TLE
//int main()  
//{ 
//    FAST_INP;
//    long long n,q, sum=0;
//    cin >> n;
//    vector<int> v(n);
//    for(int i=0;i<n;i++){
//    	cin >> v[i];
//	}
//	cin >> q;
//	for(int i=0;i<q;i++){
//		int b,c;
//		cin >> b >> c;
//		replace(v.begin(),v.end(),b,c);
//		cout << accumulate(v.begin(), v.end(), 0) << endl;
//	} 
//    return 0;
//} 
