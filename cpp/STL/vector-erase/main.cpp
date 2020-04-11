#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,x,a,b;
    cin >> n;
    vector<int> vi(n);
    for(int i=0;i<n;i++) cin >> vi[i];
    cin >> x >> a >> b;
    vi.erase(vi.begin()+x-1);
    vi.erase(vi.begin()+a-1, vi.begin()+b-1);
    cout << vi.size() << "\n";
    for(int i=0;i<vi.size();i++) cout << vi[i] << " ";
    return 0;
}

// 1 4 6 2 8 9
// 1 6 2 8 9
// 1 8 9