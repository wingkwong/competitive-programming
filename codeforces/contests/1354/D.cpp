#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

// Memory limit exceeded
// int main()  
// { 
// 	FAST_INP;
// 	int t,n,q,a;
// 	cin >> n >> q;
// 	multiset<int> ms;
// 	vector<int> b(q);
// 	for(int i=0;i<n;i++){
// 		cin >> a;
// 		ms.insert(a);
// 	}
// 	for(int i=0;i<q;i++) cin >> b[i];
// 	for(int i=0;i<q;i++){
// 		if(b[i]<0){
// 			b[i]*=-1;
// 			ms.erase(next(ms.begin(),b[i]-1));
// 		}else{
// 			ms.insert(next(ms.begin(),b[i]-1),b[i]);
// 		}
// 	}
// 	if(ms.size()==0){
// 		cout << 0 << "\n";
// 	} else {
// 		cout << *ms.begin() << "\n";
// 	}
// 	return 0;
// } 
