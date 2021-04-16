#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
 // your code goes here
int t,q,d;
  cin >> t >> q >>d;
  while (t--)
  {
      ll l=(-1LL)*2e18,r=2e18,y1=l,y2=r;
      ll curr=1LL;
      string cc;
    ll mid=(l+r)/2;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(curr==1LL)
        cout<<curr<<" "<<mid<<" "<<y1<<endl;
        else
        cout<<curr<<" "<<mid<<" "<<y1<<" "<<mid<<" "<<y2<<endl;
        cin>>cc;
        if(cc[0]=='X')
        {
            curr=2LL;
        }
        if(cc=="O")
        {
            break;
        }
        if(cc[0]=='N')
        {
            l=mid+1LL;
        }
        if(cc[0]=='P')
        {
            r=mid-1LL;
        }
    }
  }
}