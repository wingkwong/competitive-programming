#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T, n;
    cin >> T;   
    while(T--){
        bool p = false;
        cin >> n;
        if(n==1) p=true;
        else {
            for(int i=2;i*i<=n;i++){
                if(n%i==0) {
                    p=true;
                    break;
                }
            }
        }
        cout << (!p?"Prime":"Not prime") << "\n";
    }
    return 0;
}
