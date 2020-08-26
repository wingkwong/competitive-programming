/*
Codeforces Round #624 (Div. 3) - B. WeirdSort
https://codeforces.com/problemset/problem/1311/B
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int t,m,n;
    cin >> t;
    while(t--){
        // sort each possible segment to see if the overall array is same as the sorted one
        cin >> n >> m;
        vector<int> a(n),p(n);
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<m;i++) {
            int pp; cin >> pp;
            p[pp-1]=1;
        }
        for(int i=0;i<n;i++){
            // skip if index i is not the starting point of the segment
            if(p[i]==0) continue;
            int j=i;
            // look for the ending point of the segement and sort the segment
            while(j<n&&p[j])++j;
            // e.g. p=[1,3], a=[3,1,4,2]
            // after 1st sorting, a=[1,3,4,2]
            // after 2nd sorting, a=[1,3,2,4]
            sort(a.begin()+i,a.begin()+j+1);
            // update i
            i=j;    
        }
        bool f=1;
        // if the ans is YES, array a should be in ascending order.
        // else it is NO
        for(int i=1;i<n;i++) f&=(a[i-1]<=a[i]);
        if(f) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
} 