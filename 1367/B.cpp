/*
Codeforces Round #650 (Div. 3) - B. Even Array
https://codeforces.com/contest/1367/problem/B
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        int odd=0,odd1=0,even=0,even1=0,ans=0,a;
        for(int i=0;i<n;i++){
        	cin >> a;
        	if(a%2==i%2) continue;
            // calculate how many even & odd numbers for the input
        	if(a%2==0) even++;
        	else odd++;
            // calculate how many even & odd numbers for the index
        	if(i%2==0) even1++;
        	else odd1++;
		}
        // if they are equal, it means it fits the place 
        // the move would be (odd+even)/2
		cout << (even==even1&&odd==odd1?(odd+even)/2:-1) << "\n";
    }
    return 0;
} 
