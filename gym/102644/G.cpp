/*
Matrix Exponentiation - G. Recurrence With Square
https://codeforces.com/gym/102644/problem/G
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;
#define FOR(i, n) for (int i = 0; i < (n); i++)
int s;

struct Matrix
{
    vector<vector<int>> a=vector<vector<int>>(s,vector<int>(s));
    Matrix operator*(const Matrix& other) {
    	Matrix product;
        FOR(i, s) FOR(j, s) FOR(k, s) {
            product.a[i][k]=(product.a[i][k] + (ll) a[i][j]*other.a[j][k])%MOD;
        }
        return product;
    }
};

Matrix expo_power(Matrix a, ll k){
	Matrix product;
	FOR(i,s) product.a[i][i]=1;
	while(k>0){
		if(k&1) product=product*a;
		a=a*a;
		k/=2;
	}
	return product;
}

int main()  
{ 
    FAST_INP;
    int n,p,q,r; 
	ll k;
	cin>>n>>k;
	s=n+3;
	vector<int> a(n),c(n);
	FOR(i,n) cin>>a[i];
	FOR(i,n) cin>>c[i];
	cin>>p>>q>>r;
    if(k<n){
    	cout << a[k] << endl;
    	return 0;
	}
	vector<int> dp(n+3);
	for(int i=0;i<n;i++) dp[i]=a[i];
	dp[n]=1;
	dp[n+1]=n;
	dp[n+2]=n*n;
	int m[n+3][n+3];
	FOR(i,n+3) FOR(j,n+3) m[i][j]=0;
	m[n][n]=1;
	m[n+1][n+1]=1;
	m[n][n+1]=1;
	m[n+2][n+2]=1;
	m[n+1][n+2]=2;
	m[n][n+2]=1;
	m[n][n-1]=p;
	m[n+1][n-1]=q;
	m[n+2][n-1]=r;
	FOR(j,n) m[n-1-j][n-1]=c[j];
	FOR(j,n-1) m[j+1][j]=1;
	
	Matrix single;
	FOR(i,n+3) FOR(j,n+3) single.a[i][j]=m[i][j];
	Matrix total = expo_power(single,k-n+1);
	vector<int> new_dp(n+3);
	FOR(i,n+3) FOR(j,n+3) {
		new_dp[j]=(new_dp[j]+(ll)dp[i]*total.a[i][j]) % MOD;
	}
	
//	FOR(rep,k-n+1) {
//		vector<int> new_dp(n+3);
//		FOR(i,n+3){
//			FOR(j,n+3) {
//				new_dp[j]+=dp[i]*m[i][j];
//			}
//		}
//		dp=new_dp;
//	}
	cout << new_dp[n-1] << endl;
    return 0;
} 

