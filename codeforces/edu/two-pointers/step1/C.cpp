/*
ITMO Academy: pilot course - Two Pointers Method » Step 1 » C. Number of Equal
https://codeforces.com/edu/course/2/lesson/9/1/practice/contest/307092/problem/C
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)


int main()
{
    FAST_INP;
    long long N, M; cin >> N >> M;
    vector<long long> A(N), B(M);
    for(auto &x : A) cin >> x;
    for(auto &x : B) cin >> x;
    long long i = 0, j = 0, cnt1 = 0, cnt2 = 0, ans = 0;
	while(i < N && j < M) {
		cnt1 = 0, cnt2 = 0;
		while(i < N && A[i] < B[j]) i++;
		while(j < M && B[j] < A[i]) j++;
		while(i < N && A[i] == B[j]) i++, cnt1++;
		while(j < M && A[i - 1] == B[j]) j++, cnt2++;
		ans += (cnt1 * cnt2);
	}
	cout << ans << endl;
	return 0;
}