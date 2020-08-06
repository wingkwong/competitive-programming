/*
Matrix Exponentiation - C. Fibonacci
https://codeforces.com/gym/102644/problem/C
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;

//unordered_map<ll,ll> Fib;
// 
//ll fib(ll n)
//{
//    if(n<2) return 1;
//    if(Fib.find(n) != Fib.end()) return Fib[n];
//    //F[i]=F[i]-1+F[i]-2=2*F[i]-2+F[i]-3=3*F[i]-3+2*F[i]-4...
//    // i&1 : (f[i/2]*f[i/2])+(f[i/2]*f[i/2]-1)
//    // !(i&1): f[i]=(f[i/2])^2+(f[i/2]-1)^2
//    Fib[n]=(fib((n+1)/2)*fib(n/2)+fib((n-1)/2)*fib((n-2)/2))%MOD;
//    return Fib[n];
//}
// 

#define FOR(i, n) for (int i = 0; i < (n); i++)
struct Matrix
{
    long long mat[2][2];
    Matrix operator*(Matrix other)
    {
        Matrix product{{{0, 0}, {0, 0}}};
        FOR(i, 2) FOR(j, 2) FOR(k, 2)
        {
            product.mat[i][k] += mat[i][j] * other.mat[j][k];
            product.mat[i][k] %= MOD;
        }
        return product;
    }
};

int main()  
{ 
    FAST_INP;
    ll n;
    cin >> n;
    Matrix fib, ans;
    fib.mat[0][0] = 0;
    fib.mat[0][1] = 1;
    fib.mat[1][0] = 1;
    fib.mat[1][1] = 1;
    ans.mat[0][0] = 0;
    ans.mat[0][1] = 1;
    ans.mat[1][0] = 1;
    ans.mat[1][1] = 1;
	while (n) {
        if (n&1) ans=ans*fib;
        fib=fib*fib;
        n/=2;
    }
    cout << ans.mat[0][0] << endl;
    return 0;
} 

