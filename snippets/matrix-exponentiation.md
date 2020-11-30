```cpp
const int N = 2;
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
```

Usage:

```cpp
Matrix aux{{{19,7}, {6,20}}}, ans{{{1,0}, {0,1}}};
while (n) {
    if (n&1) ans=ans*aux;
    aux=aux*aux;
    n/=2;
}
cout << ans.mat[0][0] << endl;
```