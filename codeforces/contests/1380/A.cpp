/*
Educational Codeforces Round 91 (Rated for Div. 2) - A. Three Indices
https://codeforces.com/contest/1380/problem/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

//void solve(){
//	int n,ii=-1;
//	cin >> n;
//    vector<int> p(n+1);
//    for(int i=1;i<=n;i++) cin >> p[i];
//    for(int i=1;i<=n;i++){
//    	int jj=-1,kk=-1;
//    	for(int j=i+1;j<=n;j++){
//			if(p[i]<p[j]){
//				ii=i;
//				jj=j;
//			}
//			if(jj==-1) continue;
//    		for(int k=j+1;k<=n;k++){
////    			printf("%d %d %d - %d %d %d \n", i,j,k,p[i],p[j],p[k]);
//    			if(p[j]>p[k]){
//    				kk=k;
//    				cout << "YES\n";
//    				cout << ii << " " << jj << " " << kk << "\n";
//    				return;
//				}
//			}
//		}
//	}
//	cout << "NO\n";
//	return;
//}

void solve(){
	int n;
	cin >> n;
    vector<int> p(n+1);
    for(int i=1;i<=n;i++) cin >> p[i];
    for(int i=1;i<=n-2;i++) {
        // find an index j such that aj−1<aj and aj>aj+1 
    	if(p[i]<p[i+1]&&p[i+1]>p[i+2]){
    		printf("YES\n%d %d %d\n", i,i+1,i+2);
    		return;
		}
	}
	printf("NO\n");
	return;
}

int main()  
{ 
    FAST_INP;
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
} 
