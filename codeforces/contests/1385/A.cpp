/*
Codeforces Round #656 (Div. 3) - A. Three Pairwise Maximums
https://codeforces.com/contest/1385/problem/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int t,x,y,z;
    cin >> t;
    while(t--){
        cin >> x >> y >> z;
        // x,y,z should have at least two pairs
        if(x==y&&y==z&&x==z) {
			cout << "YES\n";
        	cout << x << " " << y << " " << z << "\n";
		}
        else if(x==y&&z<x&&z<y) {
			cout << "YES\n";
        	cout << x << " " << 1 << " " << z << "\n";
		}
        else if(y==z&&x<y&&x<z) {
			cout << "YES\n";
        	cout << x << " " << 1 << " " << z << "\n";
		}
        else if(x==z&&y<x&&y<z) {
			cout << "YES\n";
        	cout << 1 << " " << x << " " << y << "\n";
		}
        else cout << "NO\n";
    }
    return 0;
} 

int sol2()  
{ 
    FAST_INP;
    int t,x,y,z;
    cin >> t;
    while(t--){
    	vector<int> a(3);
    	for(auto &x:a) cin >> x;
    	sort(a.begin(),a.end());
    	if(a[1]!=a[2]) {
    		cout << "NO\n";
		} else {
			cout << "YES\n";
			cout << a[0] << " " << a[0] << " " << a[2] << "\n"; 
		}
    }
    return 0;
} 

