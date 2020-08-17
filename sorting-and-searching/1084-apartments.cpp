/*
Apartments
https://cses.fi/problemset/task/1084

There are n applicants and m free apartments. Your task is to distribute the apartments so that as many applicants as possible will get an apartment.

Each applicant has a desired apartment size, and they will accept any apartment whose size is close enough to the desired size.

Input

The first input line has three integers n, m, and k: the number of applicants, the number of apartments, and the maximum allowed difference.

The next line contains n integers a1,a2,…,an: the desired apartment size of each applicant. If the desired size of an applicant is x, he or she will accept any apartment whose size is between x−k and x+k.

The last line contains m integers b1,b2,…,bm: the size of each apartment.

Output

Print one integer: the number of applicants who will get an apartment.

Constraints
1≤n,m≤2⋅105
0≤k≤109
1≤ai,bi≤109
Example

Input:
4 3 5
60 45 80 60
30 60 75

Output:
2
*/

#include <bits/stdc++.h>
using namespace std; 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll; 
const ll MOD = 1000000007;

int main()  
{ 
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
    // #endif
    FAST_INP;
    ll n,m,k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for(auto &x:a) cin >> x;
    for(auto &x:b) cin >> x;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int ans=0;
    for(int i=0, j=0;i<n;i++){
        // printf("%d %d %d \n", a[i]-k, b[j], a[i]+k);
        while(j<m&&b[j]<a[i]-k){
            j++;
        }
        if(j<m&&b[j]<=a[i]+k) {
            j++, ans++;
        }
    }
    cout << ans << endl;
    return 0;
} 


// 45 60 60 80 
// 30 60 75