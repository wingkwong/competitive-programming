#include <bits/stdc++.h>
using namespace std; 

long long t,i,x;

long long s(long long n,long long k){
    // s3=3+6+9+..+3i    - 3i<=n
    // s3=3(1+2+3+..+i)  - i <=n/3
    // -------------------
    //  z(i)=1+2+3+..+(i-1)+i
    //  z(i)=i+(i-1)+(i-2)+...+2+1
    // 2z(i)=(i+1)+(i+1)+(i+1)..+(i+1)+(i+1)
    //  z(i)=i*(i+1)/2
    // -------------------
    // s3=3*(z(n/3))
    // s3=3*((n/3)((n/3)+1)/2)
    // sk=k*((n/k)((n/k)+1)/2)
    x = n/k;
    return (k*(x*(x+1)))/2;
}

long long  euler1(long long n){
    return s(n,3) + s(n,5) - s(n,15);
}

int main()  
{ 
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--){
        cin >> i;
        cout << euler1(i-1) << "\n";
    }
    return 0; 
}