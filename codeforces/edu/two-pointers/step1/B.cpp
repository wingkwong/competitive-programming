/*
ITMO Academy: pilot course - Two Pointers Method » Step 1 » B. Number of Smaller
https://codeforces.com/edu/course/2/lesson/9/1/practice/contest/307092/problem/B
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)


int main()
{
    FAST_INP;
    int N, M; cin >> N >> M;
    vector<int> A(N), B(M), ans;
    for(auto &x : A) cin >> x;
    for(auto &x : B) cin >> x;
    int i = 0, j = 0, cnt = 0;
	while(j < M) {
		if(i == N) {
			ans.push_back(cnt);
			j++;
			continue;
		}
		if(A[i] < B[j]) {
			i++, cnt++;
		} else {
			ans.push_back(cnt);
			j++;
		}
	}
	for(int i = 0; i < M; i++) {
		cout << ans[i] << " \n"[i == M];
	}
	return 0;
}