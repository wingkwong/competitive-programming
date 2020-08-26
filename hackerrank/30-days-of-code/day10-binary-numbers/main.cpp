#include <bits/stdc++.h>

using namespace std;



int main()
{
    int n,a[1000000],r,cnt=0,k=0,max=0;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    while(n){
        r=n%2;
        n/=2;
        a[k++]=r;
    }

    for(int i=0;i<k;i++){
        if(a[i]==1){
             cnt++;
             if(cnt>max)max=cnt;
        }
        else cnt=0;
    }
    cout << max;
    return 0;
}
