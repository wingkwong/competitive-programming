/*
ITMO Academy: pilot course - Suffix Array - A. Suffix Array - 1
https://codeforces.com/edu/course/2/lesson/2/1/practice/contest/269100/problem/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)


int main()
{
    FAST_INP;
	string s;
	cin >> s;
	s+="$";
	int n=s.size();
	vector<int> p(n),c(n);
	
	vector<pair<char,int>> a(n);
	for(int i=0;i<n;i++) a[i]={s[i],i};
	sort(a.begin(),a.end());
	for(int i=0;i<n;i++) p[i]=a[i].second;
	c[p[0]]=0;
	for(int i=1;i<n;i++){
		if(a[i].first==a[i-1].first) c[p[i]]=c[p[i-1]];
		else c[p[i]]=c[p[i-1]]+1;
	}
	int k=0;
	while((1<<k)<n){
		vector<pair<pair<int,int>,int>> a(n);
		for(int i=0;i<n;i++) a[i] = {{c[i],c[(i+(1<<k))%n]},i};
		sort(a.begin(),a.end());
		for(int i=0;i<n;i++) p[i]=a[i].second;
		c[p[0]]=0;
		for(int i=1;i<n;i++){
			if(a[i].first==a[i-1].first) c[p[i]]=c[p[i-1]];
			else c[p[i]]=c[p[i-1]]+1;
		}
		k++;
	}
	for(int i=0;i<n;i++) cout << p[i] << " ";
	return 0;
}

// Time limit exceeded on test 24	
// O(N^2 log N)
//int main()
//{
//    FAST_INP;
//	map<string,int> m;
//	string s;
//	vector<string> v;
//	cin >> s;
//	int n = s.size();
//	for(int i=0;i<n;i++){
//		m[s.substr(i,n-i)] = i;
//		v.push_back(s.substr(i,n-i));
//	}
//	sort(v.begin(),v.end());
//	cout << v.size() << " ";
//	for(int i = 0; i < v.size();i++) cout << m[v[i]] << " ";
//	return 0;
//}
