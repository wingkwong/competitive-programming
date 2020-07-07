#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
int main()  
{ 
    FAST_INP;
    int n;
    cin >> n;
    if(n==2||n==3) cout << "NO SOLUTION\n";
    else {
    	// list all even & odd numbers in descending order
    	for(int i=n-1;i>0;i-=2) cout << i << " ";
    	for(int i=n;i>0;i-=2) cout << i << " ";
	}
    return 0;
} 
