/*
D - Teleporter
https://atcoder.jp/contests/abc167/tasks/abc167_d
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
int main()  
{ 
    FAST_INP;
    long long n,k; 
    cin >> n >> k;
    long long a[n];
    unordered_map<long long,long long> m,d,c;
    bool duplicate=false;
    // read the input
    for(long long i=0;i<n;i++){
        cin >> a[i];
        // store the value to map
        m[i]=a[i];
    }
    // if you take a look at the sample input 2
    // 6 727202214173249351
    // 6 5 2 5 3 2
    // you know there is no way to traverse k times
    // by listing out the travel, you should obverse the pattern 
    // to a certain point, it starts looping
    // Example:
    // 6 5 2 5 3 2
    // 1 -> 6 -> 2 -> 5 -> 3 -> 2 -> 5 -> 3 -> 2 -> 5 ....  
    // Start from the third step, it starts the loop 2 -> 5 -> 3 
    long long i=0,step=0,kk=k;
    while(!duplicate&&kk){
        step++; // step is used to find out when a town has been visi
        if(d[i]==1){
            // if it is visited before, that is the start of the loop
            duplicate=true;
            continue;
        }
        d[i]=1; // set the current i to 1, in other word, this has been visited
        c[i]=step; // we need to store the step to another map because we need to calculate from where the looping starts
        i=m[i]-1; // -1 because it s 0 based
        kk--; // monitor if it s out of boundary
    }

    // 6 5 2 5 3 2
    // 1 -> 6 -> 2 -> 5 -> 3 -> 2 -> 5 -> 3 -> 2 -> 5 ....
    //           x              x 
    // |-----------step---------|
    //           |--------------k-c[i]---------------- ....
    // |---c[i]--|                         
    // |------------------------k--------------------- ....

    // if it s not out of boundary
    if(kk){
        // the first part (k-c[i]) is the length of the repeating pattern till k
        // the second part (step-c[i]) is the length of the repeating pattern
        // the result r is how time we need to teleport from the repeating pattern
        long long r = (k-c[i])%(step-c[i]);
        while(r>=0){
            i=m[i]-1;
            r--;
        } 
    }

    cout << i+1 << "\n";

    return 0;
} 

