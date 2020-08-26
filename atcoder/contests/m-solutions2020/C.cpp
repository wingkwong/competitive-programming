/*
M-SOLUTIONS Programming Contest 2020 - C - Marks
https://atcoder.jp/contests/m-solutions2020/tasks/m_solutions2020_c
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int n,k;
    cin >> n >> k;
    vector<long long> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n-k;i++){
    	// we don't need to calculate the grade 
    	// grade for the (K+i)-th term and that for the (K+i-1)-th term have (k-1) common elements 
    	// therefore, just compare a[i] and a[i+k]
    	if(a[i]<a[i+k]) cout <<"Yes\n";
    	else cout <<"No\n";
	}
	
    return 0;
} 

// WA
//int main()  
//{ 
//    FAST_INP;
//    int n,k;
//    cin >> n >> k;
//    vector<long long> a(n), g(n-k+1);
//    for(int i=0;i<n;i++) cin >> a[i];
//    for(int i=0;i<n-k+1;i++){
//    	int j=k+i-1;
//    	long long sum=1;
//    	for(int x=0;x<k;x++){
////    		printf("%d * %d \n", sum , a[j-x]);
//    		sum*=a[j-x];
//		}
////		printf("%d = %d\n", g[i],sum);
//		g[i] = sum;
//	}
//	for(int i=1;i<n-k+1;i++){
////		printf("%d %d \n", g[i],g[i-1]);
//		if(g[i]>g[i-1]) cout << "Yes\n";
//		else cout << "No\n";
//	}
//    return 0;
//} 
