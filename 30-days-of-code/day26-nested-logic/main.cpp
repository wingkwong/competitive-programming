#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {   
    int d1,m1,y1,d2,m2,y2,ans=0;
    
    cin>>d1>>m1>>y1>>d2>>m2>>y2;

    if (y1>y2) ans=10000;
    else if (y1==y2) {
        if (m1>m2) ans=500*(m1-m2);
        else if (m1==m2&&d1>d2) ans=15*(d1-d2);
    }
    cout<<ans<<endl; 
    return 0;
}
