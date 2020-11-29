/*
Codeforces Beta Round #4 (Div. 2 Only) - D. Mysterious Present
https://codeforces.com/problemset/problem/4/D
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

// Wrong answer on test 16
// should use DP ...
// void solve() {
// 	int n,w,h,ww,hh;
//     cin >> n >> w >> h;
//     vector<pair<pair<int,int>, int>> vp;
//     for(int i=0;i<n;i++){
//     	cin >> ww >> hh;
//     	pair<int,int> p = make_pair(ww,hh);
//     	vp.push_back({p,i});
    	
// 	}
// 	sort(vp.begin(),vp.end());
// 	int ans=0;
// 	vector<int> ans2;
// 	for(int i=0;i<n;i++){
// 		int f=vp[i].first.first;
// 		int s=vp[i].first.second;
// //		cout << "w: " << w << " h: " << h << endl;
// //		cout << "f: " << f << " s: " << s << endl;
// 		if(w<f&&h<s){
// 			ans++;
// 			ans2.push_back(vp[i].second+1);
// 			w=f;
// 			h=s;
// 		} else {
// 			continue;
// 		}
// 	}
	
// 	if(ans){
// 		cout << ans << "\n";
// 		for(int a:ans2) cout << a << " ";
// 	} else {
// 		cout << 0;
// 	}
// 	cout << "\n";
	
// //	for(int i=0;i<vp.size();i++){
// //		cout << vp[i].first.first << " " << vp[i].first.second  << endl;
// //	}
// }
const int MAXN = 5010;
int n, W, H;
int w[MAXN], h[MAXN];
vector<tuple<int, int, int>> v;
int dp[MAXN], prv[MAXN];

void print(int id) {
    if(id == -1) return ;
    print(prv[id]);
    printf("%d ", get<2>(v[id]));
}

void solve2() {
	scanf("%d%d%d", &n, &W, &H);
    for(int i = 1; i <= n; i++) {
        scanf("%d%d", w+i, h+i);
        if(w[i] > W && h[i] > H)
            v.push_back(tuple<int, int, int>(w[i], h[i], i));
    }
    sort(v.begin(), v.end());
    int ans = 0, idx = -1;
    for(int i = 0; i < (int)v.size(); i++) {
        int mx = 0, pid = -1;
        for(int j = 0; j < i; j++)
            if(get<0>(v[j]) < get<0>(v[i]) && get<1>(v[j]) < get<1>(v[i]) && mx < dp[j])
                mx = dp[j], pid = j;
        dp[i] = mx+1, prv[i] = pid;
        if(dp[i] > ans) ans = dp[i], idx = i;
    }
    printf("%d\n", ans);
    print(idx);
    puts("");
}

int main()  
{ 
    FAST_INP;
    // solve();
	solve2();
    return 0;
} 
