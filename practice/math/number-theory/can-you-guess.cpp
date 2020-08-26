#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
int main()  
{ 
    FAST_INP;
    // count how many numbers can be divided by i where i=1..v
    int n,v;
    cin >> n;
    while(n--){
        long long ans=0;
		cin >> v;
        for(int i=1;i<v;i++){
            if(v%i==0) ans+=i;
        }
        cout << ans << "\n";
	}
    return 0;
}  
