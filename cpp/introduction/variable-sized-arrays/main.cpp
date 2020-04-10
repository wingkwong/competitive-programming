#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n,q,k,i,j;
int main() {
    cin >> n >> q;
    vector<vector<int> >a(n);

    for(int i=0;i<n;i++){
        cin >> k;
        a[i].resize(k);
        for(int j=0;j<k;j++){
            cin >> a[i][j];
        }
    }

    for(int x=0;x<q;x++){
        cin >> i >> j;
        cout << a[i][j] << "\n";
    }

    return 0;
}