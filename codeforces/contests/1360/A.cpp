/*
Codeforces Round #644 (Div. 3) - A. Minimal Square
https://codeforces.com/contest/1360/problem/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)


int main()  
{ 
    FAST_INP;
    int t,a,b,s;
    cin >> t;
    while(t--){
        cin >> a >> b;
        // simplfy below AC code
        // check if 2*width > height / 2*height > width
        // take the min of them
        int s=min(max(2*a,b),max(2*b,a));
        cout << s*s << "\n";
    }
    return 0;
} 

// AC
//int main()  
//{ 
//    FAST_INP;
//    int t,a,b;
//    cin >> t;
//    while(t--){
//        cin >> a >> b;
//        if(a==b){
//        	cout << (a*2)*(a*2) << "\n";
//		} else if (a>b){
//			if(2*b>=a){
//				cout << (b*2)*(b*2) << "\n";
//			} else {
//				cout << (a*a) << "\n";
//			}
//		} else if(a<b){
//			if(2*a>=b){
//				cout << (a*2)*(a*2) << "\n";
//			} else {
//				cout << (b*b) << "\n";
//			}
//		}
//    }
//    return 0;
//} 

