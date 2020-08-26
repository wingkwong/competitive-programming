#include <bits/stdc++.h>

using namespace std;


int f(int n, vector<int>& memo){
    if(memo[n]) return memo[n];
    memo[n] = f(n-1,memo)+f(n-2,memo);
    return memo[n];
}

int fibonacci(int n) {
    vector<int> memo(n+1,0);
    memo[0]=0;
    memo[1]=memo[2]=1;
    return f(n, memo);
}

int main() {
    int n;
    cin >> n;
    cout << fibonacci(n);
    return 0;
}
