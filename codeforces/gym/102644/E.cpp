/*
Matrix Exponentiation - E. Knight Paths
https://codeforces.com/gym/102644/problem/E
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;
#define FOR(i, n) for (int i = 0; i < (n); i++)
int s=65;

struct Matrix
{
    vector<vector<unsigned int>> a=vector<vector<unsigned int>>(s,vector<unsigned int>(s));
    Matrix operator*(const Matrix& other) {
    	Matrix product;
        FOR(i, s) FOR(j, s) FOR(k, s) {
            product.a[i][k]+=a[i][j]*other.a[j][k];
        }
        return product;
    }
};

Matrix expo_power(Matrix a, int k){
	Matrix product;
	FOR(i,s) product.a[i][i]=1;
	while(k>0){
		if(k&1) product=product*a;
		a=a*a;
		k/=2;
	}
	return product;
}

bool inside(int row, int col){
	return 0<=min(row,col)&&max(row,col)<8;
}

int main()  
{ 
    FAST_INP;
    int k; cin >> k;
    k++;
    Matrix single;
	FOR(row,8) FOR(col,8) {
    	for(int dr:{-2,-1,1,2}) {
    		for(int dc:{-2,-1,1,2}){
    			if(abs(dr)!=abs(dc)){
    				int new_row=row+dr;
    				int new_col=col+dc;
    				if(inside(new_row,new_col)){
    					single.a[8*row+col][8*new_row+new_col]=1;
					}
				}
			}
		}
	}
	for(int i=0;i<=64;i++) {
		single.a[i][64]=1;
	}
	Matrix total = expo_power(single,k);
	cout << total.a[0][64] << endl;
    return 0;
} 

