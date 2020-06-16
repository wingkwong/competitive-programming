/*
CodeChef June Challenge 2020 Division 2 - Covid Sampling (Challenge)
https://www.codechef.com/JUNE20B/problems/COVDSMPL
*/

/*
P.S: I have no idea the usage of P 
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int solve(vector<vector<int>>& arr, int r1, int c1, int r2, int c2, int cnt){
    int X;
	if(cnt==0){
		for(int i=r1-1;i<r2;i++){
			for(int j=c1-1;j<c2;j++) arr[i][j]=0;
		}
		return 0;
	}  else if(r1==r2&&(c2-c1==cnt-1)){
		for(int i=c1-1;i<c2;i++) arr[r1-1][i]=1;
		return cnt;
	} else if(r2>r1){
		int d=(r1+r2)/2;
		if((d-r1)>(r2-(d+1))) {
			cout<<1<<" "<<r1<<" "<<c1<<" "<<d<<" "<<c2<<endl;
			scanf("%d",&X);
//			cout << "debug X: " << X << endl;
			if(X==-1) exit(0);
			if(cnt==-1) return -1;
			int n=solve(arr,r1,c1,d,c2,X);
			if(cnt==-1||n==-1) return -1;
			solve(arr,d+1,c1,r2,c2,cnt-X);
		} else {
			cout<<1<<" "<<d+1<<" "<<c1<<" "<<r2<<" "<<c2<<endl;
			scanf("%d",&X);
//			cout << "debug X: " << X << endl;
			if(X==-1) exit(0);
			if(cnt==-1) return -1;
			int n = solve(arr,d+1,c1,r2,c2,X);
			if(cnt==-1||n==-1) return -1;
			solve(arr,r1,c1,d,c2,cnt-X);
		}
		return cnt;
	} else {
		int d=(c1+c2)/2;
		if((d-c1)>(c2-(d+1))){
			cout<<1<<" "<<r1<<" "<<c1<<" "<<r2<<" "<<d<<endl;
			scanf("%d",&X);
//			cout << "debug X: " << X << endl;
			if(X==-1) exit(0);
			if(cnt==-1) return -1;
			int n = solve(arr,r1,c1,r2,d,X);
			if(cnt==-1||n==-1) return -1;
			solve(arr,r1,d+1,r2,c2,cnt-X);
		} else {
			cout<<1<<" "<<r1<<" "<<d+1<<" "<<r2<<" "<<c2<<endl;
			scanf("%d",&X);
//			cout << "debug X: " << X << endl;
			if(X==-1) exit(0);
			if(cnt==-1) return -1;
			int n = solve(arr,r1,(d+1),r2,c2,X);
			if(cnt==-1||n==-1) return -1;
			solve(arr,r1,c1,r2,d,cnt-X);
		}
		return cnt;
	}
}

int main() 
{ 	
	FAST_INP;
    int t; scanf("%d",&t);
    while(t--){
	    int n,p,X;
	    scanf("%d",&n);
	    scanf("%d",&p);
	    vector<vector<int>> arr(n,vector<int>(n,0));
	    cout<<1<<" "<<1<<" "<<1<<" "<<n<<" "<<n<<endl;
	    scanf("%d",&X);
	    if(X==-1) exit(0);
	    solve(arr,1,1,n,n,X);
	    printf("2\n");
        fflush(stdout);
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                printf("%d ",arr[i][j]);
                fflush(stdout);
            }
            printf("\n");
            fflush(stdout);
        }
        scanf("%d",&X);
        if(X==1) continue;
        if(X==-1) exit(0);
	}
	return 0;
}