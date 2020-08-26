#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,q,y;
    cin >> n;
    vector<int> vi(n+1);
    vector<int>::iterator it;
    for(int i=1;i<=n;i++){
        cin >> vi[i];
    }
    cin >> q;
    for(int i=0;i<q;i++){
        cin >> y;
        it=lower_bound(vi.begin(),vi.end(),y);
        cout << (vi[it-vi.begin()] == y?"Yes ":"No ");
        cout << it-vi.begin() << "\n";
    }
    return 0;
}
