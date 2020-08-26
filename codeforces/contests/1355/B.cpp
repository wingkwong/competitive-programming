/*
Codeforces Round #643 (Div. 2) - B. Young Explorers
https://codeforces.com/contest/1355/problem/B
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)


int main()  
{ 
    FAST_INP;
    int n,t;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> e(n);
        // read the input
        for(int i=0;i<n;i++) cin >> e[i];
        // put the largest inexperience explorers to the end
		sort(e.begin(),e.end());
		int p=0,ans=0;
		for(int i=0;i<n;i++){
			// check that inexperience of the last explorer is not greater than the group size
			// create a new group only when it is possible
			if(++p==e[i]){
				ans++;
				p=0;
			}
		}
		cout << ans << "\n";
    }
    return 0;
} 



// WA
//int main()  
//{ 
//    FAST_INP;
//    int n,t;
//    cin >> t;
//    while(t--){
//        cin >> n;
//        vector<int> e(n);
//        map<int,int> m;
//        for(int i=0;i<n;i++){
//        	cin >> e[i];
//		}
//		sort(e.begin(),e.end());
//		int s,ans=0;
//		for(int i=0;i<n;i++){
//			s=e[i];
//			if(s==1) {
//				ans++;
//				continue;
//			}
//			
//			if(!m[s]){
//				m[s]++;
//				continue;
//			}
//			
//			m[s]++;
//			
//			if(m[s]==s) {
//				m[s]=0;
//				ans++;
//			}
//		}
//		cout << ans << "\n";
//    }
//    return 0;
//} 
// 1 2 2 2 2 2 2
// 1    1  1   1
// 1 1   1   1

// 1 3 3 4 4 4 4
// 1            1

// 0 1 2 3 4 5 6 -- n =7
// 1 2 2 3 3 3 3
// 1   1     1

// * 1 1 2 2 3 13 314
// 	 1 1   1      

//1
//5
//1 3 314 13 1
//314 13 3 2 2 1 1
// x   x 1     1 1
// x   x    1 1 1 1
//
//1 1 2 2 3 3 4
//1 1 1    x x x

