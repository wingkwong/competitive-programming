#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    vector<int> vi(n);
    for(int i=0;i<n;i++) cin >> vi[i];
    sort(vi.begin(),vi.end());
    for(int i=0;i<n;i++) cout << vi[i] << " ";
    return 0;
}
