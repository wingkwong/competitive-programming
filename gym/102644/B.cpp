/*
Matrix Exponentiation - B. String Mood
https://codeforces.com/gym/102644/problem/B
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;

//vector<vector<ll>> multiply(vector<vector<ll>>& a, vector<vector<ll>>& b){
//	vector<vector<ll>> p(2,vector<ll>(2));
//	p={{0,0},{0,0}};
//	for(int i=0;i<2;i++){
//		for(int j=0;j<2;j++){
//			for(int k=0;k<2;k++){
//				ll ab = (a[i][j]*b[j][k])%MOD;
//				p[i][k]=(p[i][k]+ab)%MOD;
//			}
//		}
//	}
//	return p;
//}
//
//vector<vector<ll>> solve(vector<vector<ll>>& a, int n) {
//	vector<vector<ll>> ans(2,vector<ll>(2));
//	ans={{1,0},{0,1}};
//	while(n){
//		if(n&1) ans=multiply(ans,a);
//		n/=2;
//		a=multiply(a,a);
//	}
//	return ans;
//}

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
    Matrix aux{{{19,7}, {6,20}}}, ans{{{1,0}, {0,1}}};
	while (n) {
        if (n&1) ans=ans*aux;
        aux=aux*aux;
        n/=2;
    }
    cout << ans.mat[0][0] << endl;
    return 0;
} 


//H--(19)--H
//H--(7) --S
//S--(6) --H
//S--(20)--S
