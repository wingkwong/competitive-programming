/*
Matrix Exponentiation - D. Count Paths
https://codeforces.com/gym/102644/problem/D
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const int N = 101;
const ll MOD = 1000000007;

#define FOR(i, n) for (int i = 0; i < (n); i++)
struct Matrix
{
    long long mat[N][N];
    Matrix operator*(Matrix other)
    {
        Matrix product{{{0, 0}, {0, 0}}};
        FOR(i, N) FOR(j, N) FOR(k, N)
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
    ll n,m,k,a,b,res=0;
    cin >> n >> m >> k;
    Matrix aux, ans;
    FOR(i,n){
    	ans.mat[i][i]=1;
	}
    FOR(i,m){
    	cin >> a >> b;
    	aux.mat[a-1][b-1]=1;
	}
	while(k) {
        if (k&1) ans=ans*aux;
        aux=aux*aux;
        k/=2;
    }
    FOR(i,n) FOR(j,n) {
    	if(ans.mat[i][j]!=0) {
    		res += ans.mat[i][j];
    		res %= MOD;
		}
	}
	cout << res << endl;
    return 0;
} 
