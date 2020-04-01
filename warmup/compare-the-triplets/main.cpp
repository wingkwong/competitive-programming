#include <bits/stdc++.h>
using namespace std; 

int a1, a2, a3, b1, b2, b3, a, b;

int main()  
{ 
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> a1 >> a2 >> a3;
    cin >> b1 >> b2 >> b3;
    a = (a1 > b1) + (a2 > b2) + (a3 > b3);
    b = (b1 > a1) + (b2 > a2) + (b3 > a3);
    cout << a << " " << b;
    return 0; 
} 