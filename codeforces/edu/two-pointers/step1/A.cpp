/*
ITMO Academy: pilot course - Two Pointers Method » Step 1 » A. Merging Arrays
https://codeforces.com/edu/course/2/lesson/9/1/practice/contest/307092/problem/A
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)


int main()
{
    FAST_INP;
    int N, M; cin >> N >> M;
    vector<int> A(N), B(M), C;
    for(auto &x : A) cin >> x;
    for(auto &x : B) cin >> x;
    int i = 0, j = 0;
	while(i < N || j < M) {
		if(i == N) {
			C.push_back(B[j++]);
		} else if(j == M) {
			C.push_back(A[i++]);
		} else if(A[i] < B[j]) {
			C.push_back(A[i++]);
		} else {
			C.push_back(B[j++]);
		}
	}
	for(int i = 0; i < N + M; i++) {
		cout << C[i] << " \n"[i == N + M - 1];
	}
	return 0;
}