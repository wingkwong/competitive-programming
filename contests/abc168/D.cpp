/*
D - .. (Double Dots)
https://atcoder.jp/contests/abc168/tasks/abc168_d

Haven't solved this question yet! I think the approach should be bfs

*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int n,m,a,b; 
int ans=0;
vector<vector<int>> l;

void bfs(int v, int x, vector<bool>& vis, vector<vector<int>>& l){
	vector<int> q,t;
	vis[x]=true;
	q.push_back(x);
	while(!q.empty()){
		ans++;
		x=q.front();
		q.erase(q.begin());
		for(auto lt=l[x].begin();lt!=l[x].end();lt++){
			if(!vis[*lt]){
				vis[*lt]=true;
				t[*lt]=x;
				q.push_back(*lt);
			}
		}
	}
	
	if(ans==n){
		cout << "Yes\n";
		for(int i=2;i<=n;i++){
			cout << t[i] << "\n";
		}
	} else {
		cout << "No\n";
	}
}

int main()  
{ 
    FAST_INP;
    cin >> n >> m;
    vector<bool> vis(n,false);
    while(m--){
        cin >> a >> b;
        l[a].push_back(b);
    }
    bfs(n,1,vis,l);
    cout << ans << "\n";
    return 0;
} 
