#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    string s;

    cin>>n;
    for(int i=0;i<n;i++){
        string e,o;
        cin >> s;
        for(int j=0;j<s.size();j++){
            if(j%2==0) e+=s[j];
            else o+=s[j];
        }
        cout << e << " " << o << "\n";
    }
    return 0;
}
