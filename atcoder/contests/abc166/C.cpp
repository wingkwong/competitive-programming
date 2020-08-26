#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
int main()  
{ 
    FAST_INP;
    int n,m,a,b,ans=0; 
    unordered_set<int> s;
    cin >> n >> m;
    int h[n+1];
    for(int i=0;i<n;i++){
        cin >> h[i+1];
    }

    for(int i=0;i<m;i++){
        cin >> a >> b;
        if(h[a]>h[b]) {
            cout << "inserting a: " << a << endl;
            s.insert(a);
        }
        else if(h[a]<h[b]) {
            cout << "inserting b: " << b << endl;
            s.insert(b);
        }
    }
    cout << s.size() << "\n";
    return 0;
} 