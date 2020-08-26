#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int a,b;
    cin >> a >> b;
    for(int i=a; i<=b;i++){
        if(i==1) cout << "one" << "\n";
        else if(i==2) cout << "two" << "\n";
        else if(i==3) cout << "three" << "\n";
        else if(i==4) cout << "four" << "\n";
        else if(i==5) cout << "five" << "\n";
        else if(i==6) cout << "six" << "\n";
        else if(i==7) cout << "seven" << "\n";
        else if(i==8) cout << "eight" << "\n";
        else if(i==9) cout << "nine" << "\n";
        else if(i>9) cout << (i%2==0?"even":"odd") << "\n"; 
    }
    return 0;
}
